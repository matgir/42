/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:51:46 by Helene            #+#    #+#             */
/*   Updated: 2024/10/05 14:59:26 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Client.hpp"


// ---------------- constructors, destructors, operators overloads ---------------------

Client::Client()
: _sockFd(-1), _state(Unregistered), _server(NULL)
{ }

Client::Client(int fd, Server *server)
: _sockFd(fd), _state(Unregistered), _server(server)
{
    printf("Client constructor, _server address : %p\n", &(*(this->_server)));
}

Client::~Client()
{
    //close(_sockFd);
}

bool Client::operator!=(Client const& other)
{
    return !(*this == other);
}

Client::Client(Client const& other)
{
    *this = other;
}

Client& Client::operator=(Client const& other) 
{
    if (this == &other)
        return *this;
    
    this->_server = other._server;
    this->_sockFd = other._sockFd;
    this->_state = other._state;
    this->_modes = other._modes;
    this->_password = other._password;
    
    this->_hostname = other._hostname;
    this->_nickname = other._nickname;
    this->_realname = other._realname;
    this->_username = other._username;
    
    this->_readBuffer = other._readBuffer;
    this->_writeBuffer = other._writeBuffer;
    
    return *this;
}

bool Client::operator==(Client const& other)
{
    return (this->_nickname == other._nickname); // autre chose ?
}



// ----------------- Log in methods, additional getters -------------------

void    Client::setPassword(std::string const& newPass)
{
    _password = newPass;
}

std::string Client::getPassword(void)
{
    return this->_password;
}

std::string Client::getUserID(void) const
{
    std::string userID = ":" + getNickname() + "!" + getUsername() + "@" + getHostname();
    return userID;
}

Server& Client::getServer()
{
    return *(this->_server); // vérifier
}

int Client::getSockFd(void)
{
    return this->_sockFd;
}

std::vector<std::string> Client::getChannels(void)
{
    return this->_channelNames;
}

// ---------------- Client's state methods ----------------

// ou juste int& getState(), renvoie une reference au state que peut direct modifier, et pas besoin de setState() ?
int             Client::getState(void) const
{
    return this->_state;
}

void            Client::setState(int newState)
{
    _state = newState;
}

void    Client::addState(int state)
{
    // if ((_state & state) != state)
    _state |= state;
}

void    Client::removeState(int state)
{
    _state &= (~state);
}

// returns true if the client is in this state, false otherwise
bool    Client::checkState(int state)
{
    return ((_state & state) == state);   
}



// ------------ other getters && setters --------------

void            Client::addModes(std::string const& modes)
{
    _modes += modes;
}

std::string     Client::getModes(void)
{
    return this->_modes;
}

std::string Client::getNickname(void) const
{
    return this->_nickname;
}

void    Client::setNickname(std::string const& nick)
{
    _nickname = nick;
}

std::string     Client::getUsername(void) const
{
    return this->_username;
}
void            Client::setUsername(std::string const& user)
{
    _username = user;
}

std::string     Client::getHostname(void) const
{
    return this->_hostname;
}
void            Client::setHostname(std::string const& host)
{
    _hostname = host;
}

std::string     Client::getRealname(void) const
{
    return this->_realname;
}
void            Client::setRealname(std::string const& real)
{
    _realname = real;
}



// --------------- getters, setters on read and write buffers -------------------

std::string& Client::getReadBuffer(void)
{
    return this->_readBuffer;
}

void    Client::addToReadBuffer(std::string const &data)
{
    _readBuffer += data; 
}

void    Client::clearReadBuffer(void)
{
    _readBuffer.clear();
}

void    Client::resetReadBuffer(std::string const& newBuffer)
{
    _readBuffer = newBuffer;
}

void            Client::addToWriteBuffer(std::string const& data)
{
    _writeBuffer += data;
}

std::string&    Client::getWriteBuffer(void)
{
    return this->_writeBuffer;
}

void            Client::clearWriteBuffer(void)
{
    _writeBuffer.clear();
}

