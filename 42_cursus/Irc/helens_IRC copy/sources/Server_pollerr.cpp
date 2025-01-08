/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server_pollerr.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:26:30 by Helene            #+#    #+#             */
/*   Updated: 2024/12/18 13:45:59 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

void    Server::HandlePollErr(int fd)
{
    int errNum = errno;
    std::string reason = strerror(errNum);
    if (fd == this->_server_socket)
    {
        this->_log(ERROR, "Error on server socket : " + reason);
        serverShutdown = true;
        return ;
    }
    std::stringstream ss;
    ss << fd;
    this->_log(ERROR, "Error on socket " + ss.str() + ": " + std::string(strerror(errNum)));
    
    Client *client = getClient(fd);
    if (!client)
    {
        RemoveSocket(fd);
        return ;
    }
    
    DisconnectClient(getClient(fd), reason); 
    RemoveClient(getClient(fd));
}