/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:51:49 by Helene            #+#    #+#             */
/*   Updated: 2024/11/22 19:11:55 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

/* -------------------------- CONSTRUCTORS, DESTRUCTOR ------------------------------- */

void    Server::setCreationDate(void)
{
    time_t time = std::time(0);
    this->_creationDate = std::string(ctime(&time));
}

Server::Server(std::string const& port, std::string const& password)
: _port(port), _password(password)
{
    this->setCreationDate();
    
    this->_logger.log(INFO, "Server created");
    std::stringstream ss;
    ss << &(*this);
    // this->_logger.log(INFO, "Server address : " + ss.str());
}

// std::stringstream : support input and output operations, can add and use info in
// it, used for string parsing and formating

Server::~Server()
{
    // close(_server_socket);
    // ou le fait direct dans shutdownServer() ?
}

Server::Server(Server const& other)
{
    *this = other;
}

Server& Server::operator=(Server const& other)
{
    (void)other; // ou se fait chier a tt coder ? sachant qu'est en privé et que ne devrait jamais vouloir copier le serveur
    return *this;
}




/* -------------------------- INIT SERVER ------------------------------- */

void    Server::InitServer(void)
{
    
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; //set to IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP stream socket
    hints.ai_flags = AI_PASSIVE; // localhost by default, means that it fills it with
                                    // our own ip
    if (getaddrinfo(NULL, (this->_port).c_str(), &hints, &res))
    {
        serverShutdown = true;
        throw(std::runtime_error("getaddrinfo() call failed"));
    }
    _server_socket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    
    this->_logger.log(INFO, "Connection socket created");
    // maybe add a check to verify that it returned 0 and not -1 

    int en = 1;
    // The setsockopt() API allows the application to reuse the local address when the server is restarted before the required wait time expires.
	if(setsockopt(_server_socket, SOL_SOCKET, SO_REUSEADDR, &en, sizeof(en)) == -1)
    {
        serverShutdown = true;
		throw(std::runtime_error("failed to set option (SO_REUSEADDR) on server socket"));
    }
	
    // The fcntl() API sets the socket to be nonblocking
    if (fcntl(_server_socket, F_SETFL, O_NONBLOCK) == -1) //-> set the socket option (O_NONBLOCK) for non-blocking socket
    {
        serverShutdown = true;
		throw(std::runtime_error("failed to set option (O_NONBLOCK) on server socket"));
    }
    
    // The bind() API gets a unique name for the socket.
    if (bind(_server_socket, res->ai_addr, res->ai_addrlen))
    {
        close(_server_socket);
        serverShutdown = true;
        throw(std::runtime_error("bind error : port already in use"));
    }
    
    // makes the socker passive
    if (listen(_server_socket, BACKLOG))
    {
        close(_server_socket);
        serverShutdown = true;
        throw(std::runtime_error("call to listen() on socket server failed"));
    }
    
    pollfd newPoll;

    newPoll.fd = _server_socket;
    newPoll.events = POLLIN;
    newPoll.revents = 0;
    (this->_sockets).push_back(newPoll);
    
    freeaddrinfo(res);

    // debug
    std::stringstream ss;
    ss << _server_socket;
    this->_logger.log(INFO, "Server listening on port " + this->_port + ", with socket " + ss.str());
}


/* -------------------------- MAIN LOOP ------------------------------- */

/* 
POLLIN : there is data to read
POLLOUT : Writing is now possible
POLLHUP : Hang up. When reading from a stream socket, this event merely indicates that the peer
    closed its end of the channel.  Subsequent reads from the channel will return 0 (end of file) 
    only after all outstanding data in the channel has been consumed.
POLLERR : Error condition

* poll : 
* The accept() and recv() APIs are completed when the EWOULDBLOCK is returned.

*/
void    Server::RunServer()
{ 
    // this->_logger.log(DEBUG, "In RunServer()");
    while (!serverShutdown)
    {
        // The poll() API allows the process to wait for an event to occur and to wake up the process when the event occurs.
        if (poll(&this->_sockets[0], _sockets.size(), -1) == -1)
        {
            int errNum = errno;
            if (errNum != EINTR) // EINTR : A signal occurred before any requested event
                throw(std::runtime_error("poll() failed"));
            break;
        }
                
        for (size_t i = 0; i < _sockets.size() && !serverShutdown; i++)
        {           
            if (_sockets[i].revents & POLLERR)
                HandlePollErr(_sockets[i].fd);
            else if (_sockets[i].revents & POLLIN) // data is ready to recv() on this socket.
            {
                if (_sockets[i].fd == _server_socket)
                    AcceptClientConnection();
                else
                    ReadData(_sockets[i].fd);
            }
            else if (_sockets[i].revents & POLLOUT) // we can send() data to this socket without blocking.
                handlePollOut(_sockets[i].fd);
            else 
                continue ;
        }
    }
    
    // ShutdownServer();
}



/* -------------------------- GETTERS, SETTERS ------------------------------- */

// quel type renvoyer ? pointeur, iterateur, ... ?
Client  *Server::getClient(int fd)
{
    clients_it cli = this->_clients.find(fd);
    if (cli == _clients.end())
        return NULL;
    return &(cli->second);
}

Client  *Server::getClientByNick(std::string const& nick)
{
    for (clients_it it = _clients.begin(), end = _clients.end(); it != end; it++)
    {
        if (it->second.getNickname() == nick)
            return &(it->second);    
    }
    return NULL;
}

std::string     Server::getCreationDate(void)
{
    return _creationDate;
}

Channel     *Server::getChannel(std::string const& name)
{
    channels_it it = this->_channels.find(name);
    if (it == _channels.end())
    {
        this->_log(ERROR, "Channel " + name + " does not appear in the Server's channels registry");
        // throw std::runtime_error("Error : Channel " + name + " does not appear in the Server's channels registry");
        return NULL;
    }
    return &(it->second);     
}

/* -------------------------- ADD, REMOVE CLIENT ------------------------------- */

void    Server::AddClient(int fd)
{
    pollfd newClient;

    newClient.fd = fd;
    newClient.events = POLLIN | POLLOUT;
    newClient.revents = 0;
    (this->_sockets).push_back(newClient);
    
    Client cli(fd, this);
    this->_clients[fd] = cli; // erreur de compilation liée aux constructeurs, pourquoi ?
    
    // this->_clients.insert(std::pair<int, Client>(fd, cli));

}

// pointeur ou reference a un client ?
/*
    -> Dans la classe Channel :
        -   créer une methode pour envoyer un msg a tous les clients de ce channel 
            (sauf au client étant a l'origine de ce msg)
    -> Dans la classe Serveur :
        -   getChannel(std::string channelName) permettant de recup un channel a partir du nom
        
=>  pour envoyer un msg a tous les clients ayant des channels en commun avec le client déconnecté,
    peut 1) parser la liste des channels dans lesquelles est ce client, appeler getChannel() pour 
            chacun des channels, et pour chaque channel appeler la méthode Channel::distributeToAll(Client &client),
            qui distribue un msg a tous les clients du channel sauf celui spécifié en paramètre (car est la source du msg)
         2) parser la liste des channels existants dans le serveur, checker pour chaque channel si le client est dedans
            (nécessite la méthode bool Channel::isIn(std::string const& client, ou Client const& client)),
            puis distributeToAll() si ce client est dans le channel
    
    DANS TOUS LES CAS : ne peut pas direct envoyer le msg. ajouter chaque recipient a une liste,
        puis envoyer un msg a tous les recipients de cette liste quand a fini de parser tous les channels
        dans lesquels était le client disconnected. sinon risque d'envoyer des doublons (si le client
        déconnecté a plus d'un channel en commun avec un autre client par ex)
            
*/

void    Server::InformOthers(Client &client, std::string const& source,  std::string const& msg)
{
    std::map<std::string, Client*> recipients; // diff entre map et set ?
    std::vector<std::string> channels = client.getChannels();
    
    // parse Client's Channels and fill recipients vector
    for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); it++)
    {
        Channel *currentChan = this->getChannel(*it);
        
        for (std::map<std::string, Client*>::iterator itt = currentChan->getAllMembers().begin(); itt != currentChan->getAllMembers().end(); itt++)
        {
            if (recipients.empty() || recipients.find(itt->first) != recipients.end())
                recipients[itt->first] = itt->second;
        }
    }
    
    for (std::map<std::string, Client*>::iterator it = recipients.begin(); it != recipients.end(); it++)
        it->second->addToWriteBuffer(source + " " + msg + CRLF);
}

void    Server::updateNick(Client &client, std::string const& oldNick, std::string const& newNick)
{
    for (channels_it it = this->_channels.begin(), end = this->_channels.end(); it != end; it++)
    {
        if (it->second.isMember(oldNick) || it->second.isInvited(oldNick))
            it->second.updateNickOnChannel(oldNick, newNick);
    } 
}

// method to call in case of error return (poll(), recv() )
void    Server::DisconnectClient(Client *client, std::string const& reason = DEPARTURE_REASON)
{    
    // InformOfDisconnect(*client, reason);
    InformOthers(*client, client->getUserID(), "QUIT :" + reason);
    client->setState(Disconnected);
}

void    Server::RemoveSocket(int client_fd)
{
    for (poll_it it = _sockets.begin(); it != _sockets.end(); it++)
    {        
        if (it->fd == client_fd)
        {
            _sockets.erase(it);
            break;
        }
    }
}

/*
todo 
If a client connection is closed without the client issuing a QUIT command to the server, the server MUST 
distribute a QUIT message to other clients informing them of this, distributed in the same way as 
an ordinary QUIT message.
Servers MUST fill <reason> with a message reflecting the nature of the event which caused it to happen.

This message may also be sent from the server to a client to show that a client has exited from the network. 
This is typically only dispatched to clients that share a channel with the exiting user.
*/
void    Server::RemoveClient(Client *client)
{
    int client_fd = client->getSockFd();
    clients_it it = _clients.find(client_fd);
    
    RemoveSocket(client_fd);
    if (close(client_fd) == -1)
        std::perror("close() :");
    if (it == _clients.end())
        return ; // client does not exist
    _clients.erase(it);

    /* for (poll_it it = _sockets.begin(); it != _sockets.end(); it++)
    {        
        if (it->fd == client_fd)
        {
            _sockets.erase(it);
            break;
        }
    } */
    }




/* -------------------------- COMMANDS' ADDITIONAL METHODS ------------------------------- */

bool    Server::nickInUse(std::string const& newNick)
{
    for (clients_it it = this->_clients.begin(); it != this->_clients.end(); it++)
    {
        if (it->second.getNickname() == newNick) // check si it->seconf.getNickname().empty() ?
            return true;
    }
    return false;
}



/* -------------------------- Channels methods ------------------------------- */

void    Server::addChannel(Channel &newChannel, std::string const& name)
{
    if (this->_channels.find(name) == this->_channels.end())
        this->_channels[name] = newChannel;
}

void    Server::removeChannel(std::string const& name)
{
    Server::channels_it it = this->_channels.find(name);
    if (it != this->_channels.end())
        this->_channels.erase(it);
}

bool    Server::channelExists(std::string const& channel)
{
   for ( Server::channels_it it = this->_channels.begin(); it != this->_channels.end(); it++)
   {
        if (it->first == channel)
            return true;
   }
   return false;
}

/* -------------------------- Restart and Shutdown ------------------------------- */

// à coder
void    Server::RestartServer() 
{
    this->_logger.log(INFO, "Restarting server");
}


void    Server::ShutdownServer() 
{
    this->_logger.log(INFO, "Shutting down server");
    
    for (poll_it it = _sockets.begin(); it != _sockets.end(); it++)
        close(it->fd);

    // informer les clients de la fermeture du serveur 

    // delete clients (autre chose a faire que juste close les sockets ?)

    // delete channels -> is there anything to do about that here ?
    
}