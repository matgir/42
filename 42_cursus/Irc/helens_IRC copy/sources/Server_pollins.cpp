/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server_pollins.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:32:32 by hlesny            #+#    #+#             */
/*   Updated: 2024/12/18 14:04:55 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

void    Server::AcceptClientConnection(void)
{
    struct sockaddr_in  client_addr;
    socklen_t           addr_size = sizeof(client_addr);

    int newClient = accept(_server_socket, (struct sockaddr *)&client_addr, &addr_size);
    if (newClient == -1)
    {
        int errNum = errno;
        this->_logger.log(INFO, std::string("Could not accept connection : ") + strerror(errNum));
        return ;
    }
    
    // la rend non bloquante, car accept() est une fonction bloquante 
    if (fcntl(newClient, F_SETFL, O_NONBLOCK) == -1)
    {
        perror("fcntl : ");
        close(newClient);
        return ;
    }
    
    AddClient(newClient);
    
    std::stringstream ss;
    ss << newClient;
    this->_logger.log(INFO, "New connection! Client socket : " + ss.str());
}


void    Server::ReadData(int fd)
{
    char        buffer[BUFSIZ];
    std::string msg;
    memset(&buffer, 0, BUFSIZ);
    
    Client *client = getClient(fd); 
    if (!client) // fd pas dans la liste des server-clients sockets sur ecoute
    {
        std::stringstream ss;
        ss << "Could not locate client " << fd << " on the server.";
        _log(ERROR, ss.str());
        RemoveSocket(fd);
        return ;
    }

    if (client->checkState(Disconnected))
    {
        this->RemoveClient(client);
        return ;
    }
    

    int bytes_read = recv(client->getSockFd(), buffer, BUFSIZ, 0);
    if (bytes_read == -1)
    {
        int errNum = errno;
        std::stringstream ss;
        ss << client->getSockFd();
        this->_logger.log(INFO, "Client " + ss.str() + " : recv() failed");
        DisconnectClient(client, std::string(strerror(errNum))); 
        RemoveClient(client);
    }
    else if (!bytes_read) // EOF, ie closed connection on the other side
    {
        std::stringstream ss;
        ss << client->getSockFd();
        this->_logger.log(INFO, "Client " + ss.str() + " disconnected"); 
        DisconnectClient(client, ERROR_DEPARTURE);
        RemoveClient(client);
    }
    else
    {
        if (bytes_read > 511)
        {
            buffer[510] = '\r';
            buffer[511] = '\n';
            bytes_read = 512;
        }
        client->addToReadBuffer(std::string(&buffer[0], &buffer[bytes_read]));
        
        // Gestion Ctrl+D
        size_t pos = (client->getReadBuffer()).find("\r\n");
        if (pos == std::string::npos)
            return ;
        
        ProcessBuffer(client);
    }
}



/*  A message contains at least two parts: the command and the command parameters. There may be at most 15 parameters. 
    The command and the parameters are all separated by a single ASCII space character. 
    
    Some messages also include a prefix before the command and the command parameters. 
    The presence of a prefix is indicated with a single leading colon character. 
    The prefix is used to indicate the origin of the message. 
    For example, when a user sends a message to a channel, the server will forward that message to all the users in the channel,
    and will include a prefix to specify the user that sent that message originally.

    When the last parameter is prefixed with a colon character,
    the value of that parameter will be the remainder of the message (including space characters).
    ex -> PRIVMSG rory :Hey Rory...

    
    These message parts, and parameters themselves, are separated by one, OR MORE, ASCII SPACE characters (' ', 0x20).
*/

void    Server::ParseLine(std::string line, CommandContext &ctx)
{
    std::string prefix;
    std::string command;
    std::vector<std::string> parameters;

    std::string::iterator begin = line.begin();
    std::string::iterator it;

    // if prefix
    if (line[0] == ':')
    {
        while (begin != line.end() && *begin == ' ')
            begin++;
        it = std::find(begin, line.end(), ' ');
        prefix = std::string(begin, it);
        begin = it;
        if (begin != line.end()) 
            begin++;
    }

    // find command
    while (begin != line.end() && *begin == ' ')
            begin++;
    it = std::find(begin, line.end(), ' ');
    command = std::string(begin, it);
    begin = it;
    if (begin != line.end())
        begin++;

    while (it != line.end())
    {
        while (begin != line.end() && *begin == ' ')
            begin++;
        if (begin != line.end() && (*begin) == ':')
        {
            begin++;
            parameters.push_back(std::string(begin, line.end())); // retire le ':' du debut 
            break;
        }
        it = std::find(begin, line.end(), ' ');
        parameters.push_back(std::string(begin, it));
        begin = it;
        if (begin != line.end())
            begin++;
    }

    ctx.fillCommand(prefix, command, parameters);
}

void Server::ProcessCommand(std::string const& line, Client* client)
{
    if (line.empty()) // Empty messages are silently ignored (rfc 2812)
        return ;
        
    CommandContext ctx(*client);

    // extract prefix, command and command parameters from the line sent by client.
    ParseLine(line, ctx);
    
    std::string cmd = ctx.getCommand();
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), toupper);
    ctx.setCommand(cmd);
    
    std::map<std::string, CommandExecutor>::iterator it = _commandsHandler._commands.find(cmd);
    if (it == _commandsHandler._commands.end())
    {
        client->addToWriteBuffer(ERR_UNKNOWNCOMMAND(client->getNickname(), cmd));
        return ;
    }
    
    this->_logger.log(DEBUG, "Processing command <" + cmd + ">");
    if (it->second)
        it->second(ctx);
    
}


/* 
si la socket etait bloquée, peut avoir écrit plusieurs messages à la suite qui doivent etre traités en meme temps
 -> split selon les "\r\n"
 -> s'il reste des trucs après le dernier CRLF, les laisser dans le ReadBuffer du client (il ne restera donc à ce jour
    dedans plus que le début de message ne finissant pas encore par un CRLF, le reste aura été éffacé)
->  pour chaque message reçu, le parser et éxecuter la commande correspondante 
 */

void    Server::ProcessBuffer(Client* &client) 
{
    std::string::iterator it;
    std::string updatedBuffer;
    size_t pos;
    
    pos = client->getReadBuffer().find(CRLF); 
    while (pos != std::string::npos)
    {
        it = client->getReadBuffer().begin();
        std::string test = std::string(it, it + pos);

        std::stringstream ss; ss << client->getSockFd() << ' ' << client->getNickname();
        this->_logger.log(DEBUG, "<Client " + ss.str() + "><RECV> " + std::string(it, it + pos));
        
        ProcessCommand(std::string(it, it + pos), client);
        
        updatedBuffer = client->getReadBuffer().substr(pos + 2);
        client->resetReadBuffer(updatedBuffer);
        pos = client->getReadBuffer().find(CRLF);
    }
}

