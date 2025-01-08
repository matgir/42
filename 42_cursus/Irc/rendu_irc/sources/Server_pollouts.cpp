/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server_pollouts.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:35:43 by hlesny            #+#    #+#             */
/*   Updated: 2024/12/18 14:07:10 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

void    Server::SendWriteBuffer(Client *client)
{
    std::string toSend = client->getWriteBuffer();
    if (toSend.empty() || toSend.find(CRLF) == std::string::npos)
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
        ss << client->getSockFd() << ' ' << client->getNickname();
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
    
    SendWriteBuffer(client);
    if (client->checkState(Disconnected))
        RemoveClient(client);    
}