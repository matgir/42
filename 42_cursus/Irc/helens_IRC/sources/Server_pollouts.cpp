/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server_pollouts.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:35:43 by hlesny            #+#    #+#             */
/*   Updated: 2024/12/17 10:48:38 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

void    Server::SendWriteBuffer(Client *client)
{
    // Client  *client;
    
    // client = this->getClient(fd);
    // if (client == NULL) // client does not exist 
    // {
    //     std::stringstream ss;
    //     ss << "Could not locate client " << fd << " on the server.";
    //     _log(ERROR, ss.str());
    //     RemoveSocket(fd);
    //     return;
    // }

    std::string toSend = client->getWriteBuffer();
    if (toSend.empty() || toSend.find(CRLF) == std::string::npos) //tocheck : rajouter check pr savoir si CRLF est a la fin du buffer. sinon, juste envoyer juqu a ce delimiteur, mettre le buffer a jour en consequence
        return ;
    
    int bytes_sent = send(client->getSockFd(), toSend.c_str(), toSend.size(), 0);

    if (bytes_sent == -1)
    {
        std::perror("send() :");
        return ;
    }
    else
    {
        std::stringstream ss;
        // ss << client->getSockFd();
        ss << client->getSockFd() << ' ' << client->getNickname();//debugmg
        _logger.log(DEBUG, "<Client " + ss.str() + "><SEND> " + toSend);
    }
    client->clearWriteBuffer();
}

void    Server::handlePollOut(int fd)
{
    Client  *client;
    
    client = this->getClient(fd);
    if (client == NULL) // client does not exist 
    {
        std::stringstream ss;
        ss << "Could not locate client " << fd << " on the server.";
        _log(ERROR, ss.str());
        RemoveSocket(fd);
        return;
    }
    
    //todel 
    if (client->checkState(Disconnected))
        std::cout << "debug" << std::endl;
    
    SendWriteBuffer(client);
    // check if client is disconnected. Or is there another place to do it ?
    if (client->checkState(Disconnected))
        RemoveClient(client);    
}