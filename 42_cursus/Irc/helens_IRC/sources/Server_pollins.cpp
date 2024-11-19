/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server_pollins.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:32:32 by hlesny            #+#    #+#             */
/*   Updated: 2024/10/04 17:53:53 by hlesny           ###   ########.fr       */
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
    if (fcntl(newClient, F_SETFL, O_NONBLOCK))
    {
        perror("fcntl : ");
        close(newClient);
        return ;
    }
    
    // AddToPoll(newClient, POLLIN | POLLOUT);
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

    if (client->checkState(Disconnected)) // add 'Removed' state ? 
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
        this->_logger.log(INFO, "Client " + ss.str() + " : recv() failed"); // ou perror ?
        DisconnectClient(client, std::string(strerror(errNum))); 
        RemoveClient(client);
        // exception ?
    }
    else if (!bytes_read) // EOF, ie closed connection on the other side
    {
        std::stringstream ss;
        ss << client->getSockFd();
        this->_logger.log(INFO, "Client " + ss.str() + " disconnected"); 
        DisconnectClient(client, DEPARTURE_REASON);
        RemoveClient(client);
    }
    else
    {
        // while (bytes_read > 0) // si jamais BUFSIZ n etait pas assez grand
        // {
        //     msg += buffer;
        //     memset(&buffer, 0, BUFSIZ);
        //     bytes_read = recv(client->getSockFd(), buffer, BUFSIZ, 0);
        // }
        // if (bytes_read == -1)
        //     ; // throw exception
        
        // check limite des 512 caractères ou balec ?
        client->addToReadBuffer(std::string(&buffer[0], &buffer[bytes_read]));
        
        // Gestion Ctrl+D
        size_t pos = (client->getReadBuffer()).find("\r\n");
        if (pos == std::string::npos)
            return ;
        
        std::stringstream ss;
        ss << client->getSockFd();
        // _logger.log(DEBUG, "<Client " + ss.str() + "><RECV> " + client->getReadBuffer());

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
    // std::string temp;
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

    // put parameters in vector of strings
    /* Software SHOULD AVOID sending more than 15 parameters, as older client protocol documents 
    specified this was the maximum and some clients may have trouble reading more than this. 
    However, clients MUST parse incoming messages with any number of them */
    while (it != line.end())
    {
        while (begin != line.end() && *begin == ' ')
            begin++;
        if (begin != line.end() && (*begin) == ':')
        {
            begin++;
            parameters.push_back(std::string(begin, line.end())); // tej le ':' du debut 
            break;
        }
        it = std::find(begin, line.end(), ' ');
        parameters.push_back(std::string(begin, it));
        begin = it;
        if (begin != line.end())
            begin++;
    }

    ctx.fillCommand(prefix, command, parameters);
    
    // logger
    // this->_logger.log(DEBUG, "prefix = " + prefix);
    // this->_logger.log(DEBUG, "command = " + command);
    // for (size_t i = 0; i < parameters.size(); i++)
    // {
    //     std::stringstream ss;
    //     ss << i;
    //     this->_logger.log(DEBUG, "parameter " + ss.str() + " = " + parameters[i]);
    // }
}

// a faire dans CommandsHandler directement plutôt, non ?
void Server::ProcessCommand(std::string const& line, Client* &client) // Client* &client ?? verifier syntaxe, et si comprend bien ce qu'a écrit 
{
    if (line.empty()) // Empty messages are silently ignored (rfc 2812)
        return ;
        
    CommandContext ctx(*client); // est ce que le client pourra ensuite bien etre modifié via CommandContext ? Ou faut il passer un pointeur ? Pas encore tres au clair sur l'utilisation references/pointeurs 

    // extract prefix, command and command parameters from the line sent by client. update command's context ctx
    ParseLine(line, ctx);
    
    std::string cmd = ctx.getCommand();
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), toupper);
    // peut utiliser std::transform directement sur ctx.cmd, suffit juste de renvoyer une référence pour getCommand(), et non pas une copie de cmd
    ctx.setCommand(cmd);
    
    std::map<std::string, CommandExecutor>::iterator it = _commandsHandler._commands.find(cmd);
    if (it == _commandsHandler._commands.end())
    {
        client->addToWriteBuffer(ERR_UNKNOWNCOMMAND(cmd));
        return ; // unknown command
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
/*
Reflechir a la structure du code : Où faire le parsing ? 
    -> méthode serveur : doit alors écrire une méthode Client qui permette de modifier son ReadBuffer
    -> méthode client : pour chaque commande extraite, devra repasser par le Serveur pour l'executer (avoir un pointeur vers le Serveur pour chaque client ?)
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

        std::stringstream ss; ss << client->getSockFd();
        this->_logger.log(DEBUG, "<Client " + ss.str() + "><RECV> " + std::string(it, it + pos));
        // this->_logger.log(DEBUG, "current parsed command : " + std::string(it, it + pos));
        
        ProcessCommand(std::string(it, it + pos), client);
        // ParseLine(std::string(it, it + pos));
        
        updatedBuffer = client->getReadBuffer().substr(pos + 2);
        client->resetReadBuffer(updatedBuffer);
        pos = client->getReadBuffer().find(CRLF);
    }
}