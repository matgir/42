/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:56:29 by Helene            #+#    #+#             */
/*   Updated: 2024/12/17 09:56:11 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once // tester si suffit pour les inclusions multiples

#include "irc.hpp"
#include "Client.hpp"
#include "Logger.hpp"
#include "CommandsHandler.hpp"
#include "Channel.hpp"

# define    BACKLOG 10 // nombre max de demandes de connexions dans la file d'attente
// -> voir comment la gérer

extern bool serverShutdown;

class Server
{
    public :
        typedef std::vector<struct pollfd> pollfds;
        typedef pollfds::iterator   poll_it;
        typedef std::map<int, Client> clients;
        typedef clients::iterator clients_it;
        typedef std::map<std::string, Channel> channels;
        typedef channels::iterator channels_it;
        
    private :
        std::string         _port;
        std::string         _password;
        int                 _server_socket;
        pollfds             _sockets; // server-clients sockets 
        pollfds             _disconnectedClients; 
        clients             _clients;
        channels            _channels;
        Logger              _logger;
        CommandsHandler     _commandsHandler; 
        std::string         _creationDate;
        
        Server(Server const& other);
        Server&     operator=(Server const& other);
        void        setCreationDate(void);
        
    public :  
        Server(std::string const& port, std::string const& password);
        ~Server(); 
        void                InitServer(); // creates server socket, binds it to the given port, listen() on server socket
        void                RunServer(); // looping calls to poll()
         
        Client              *getClient(int fd); // checker si peut pas juste renvoyer une référence
        Client              *getClientByNick(std::string const& nick);
        Channel             *getChannel(std::string const& name); 
        
            // Client registering/log in
        void                tryLogin(Client &client);
        std::string         getPasswd(void) { return _password; }
        std::string         getCreationDate(void);
        void                sendMotd(Client &client);
        
            // POLLIN        
        void                AcceptClientConnection();
        void                AddClient(int fd);
        void                ReadData(int fd);
        void                ProcessBuffer(Client* &client);
        void                ProcessCommand(std::string const& line, Client* &client);
        void                ParseLine(std::string line, CommandContext &ctx);

            // POLLOUT
        void                handlePollOut(int fd);
        void                SendWriteBuffer(Client *client);

            // POLLERR
        void                HandlePollErr(int fd);

            // Send 'msg' to all clients having one or more channels in common with the 'client' parameter
        void                InformOthers(Client &client, std::string const& source,  std::string const& msg);
            // Set Client's state to 'Disconnected', which will later cause it to be removed from the serverr (removeClient)
        void                DisconnectClient(Client *client, std::string const& reason);
            // Remove client from the server's map<fd, client>, and from the vector of pollfds
        void                RemoveClient(Client *client);
        void                RemoveSocket(int client_fd);
        void                removeClientFromChannels(Client *client);
        
        void                RestartServer();
        void                ShutdownServer();

        void                _log(e_logLevel level, std::string const& msg) { _logger.log(level, msg); }

            // Useful for commands processing
        bool                nickInUse(std::string const& newNick);
        void                addChannel(Channel &newChannel, std::string const& name);
        void                removeChannel(std::string const& name);
        bool                channelExists(std::string const& channel);
        void                updateNick(std::string const& oldNick, std::string const& newNick); // when a client changes its nick, updates the nick associated with them in the channels they're in
        // void                updateNick(Client &client, std::string const& oldNick, std::string const& newNick); // when a client changes its nick, updates the nick associated with them in the channels they're in
};

/*
Functionalities that might have to be implemented :
The server pings its clients periodically in order to identify timed out clients. 
*/

/*
-   cant copy or assign server class, can only be created with port and password
*/
