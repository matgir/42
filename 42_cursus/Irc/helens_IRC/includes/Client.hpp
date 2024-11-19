/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:56:26 by Helene            #+#    #+#             */
/*   Updated: 2024/10/05 14:55:37 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/irc.hpp"

class Server;

// values = powers of 2s to be able to perform & and | operations 
typedef enum 
{
    Unregistered = 0,
    Nick = 1 << 0,
    User = 1 << 1,
    Registering = Nick | User, 
    Registered = 1 << 2,
    Disconnected = 1 << 3
    // Connected = 1 << 4,
}       e_state; 

/* Contains all informations about a client inside a server. 
Read incoming data on the associated socket and parse the messages. */
// A uniquement besoin d'une socket qui se connecte a un serveur distant
class Client 
{
    private :
        int         _sockFd;
        std::string _password;
        std::string _username;
        std::string _hostname;
        std::string _nickname;
        std::string _realname;
        std::string _readBuffer; // data sent by client
        std::string _writeBuffer; // data to be sent to client
        std::string _modes; // user's currently set modes
        int         _state;
        Server      *_server;

        std::vector<std::string> _channelNames;

    public :
        Client();
        Client(int fd, Server *server);
        ~Client();
        Client(Client const& other);
        Client&         operator=(Client const& other);
        bool            operator==(Client const& other);
        bool            operator!=(Client const& other);
        
        std::string     getUserID(void) const;
        int             getState(void) const;
        void            setState(int newState);
        void            addState(int state);
        void            removeState(int state);
        bool            checkState(int state);
        
        int             getSockFd(void);
        Server&         getServer();
        
        void            setPassword(std::string const& newPass);
        std::string     getPassword(void);
        void            addModes(std::string const& modes);
        std::string     getModes(void); // ?
        std::string     getNickname(void) const; // retourner une référence ?
        void            setNickname(std::string const& nick);
        std::string     getUsername(void) const; // retourner une référence ?
        void            setUsername(std::string const& user);
        std::string     getHostname(void) const; // retourner une référence ?
        void            setHostname(std::string const& host);
        std::string     getRealname(void) const; // retourner une référence ?
        void            setRealname(std::string const& real);
        
        std::string&    getReadBuffer(void);
        void            addToReadBuffer(std::string const& data);
        void            clearReadBuffer(void);
        void            resetReadBuffer(std::string const& newBuffer);
        
        void            addToWriteBuffer(std::string const& data);
        std::string&    getWriteBuffer(void);
        void            clearWriteBuffer(void);

        std::vector<std::string> getChannels(void);
};
