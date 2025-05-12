/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registration.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:58:41 by Helene            #+#    #+#             */
/*   Updated: 2024/12/18 13:17:31 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/irc.hpp"
#include "../../../includes/commands.hpp"
#include "../../../includes/Client.hpp"
#include "../../../includes/Server.hpp"

/*
If the password supplied does not match the password expected by the server,
then the server SHOULD send ERR_PASSWDMISMATCH (464) and MAY then close the connection with ERROR. 
Servers MUST send at least one of these two messages.

If the server is waiting to complete a lookup of client information 
(such as hostname or ident for a username), there may be an arbitrary wait 
at some point during registration. Servers SHOULD set a reasonable timeout for these lookups.
*/
void    Server::tryLogin(Client &client)
{
    if (this->getPasswd() != client.getPassword())
    {
        client.addToWriteBuffer(ERR_PASSWDMISMATCH(client.getNickname()));
        // Peut décider de fermer la connection avec ERROR
        return ;
    }
    
    client.addToWriteBuffer(RPL_WELCOME(client.getNickname(), std::string(SERVER_NAME), client.getNickname(), client.getUsername(), client.getHostname()));
    client.addToWriteBuffer(RPL_YOURHOST(client.getNickname(), std::string(SERVER_NAME), std::string(VERSION)));
    client.addToWriteBuffer(RPL_CREATED(client.getNickname(), this->getCreationDate()));
    client.addToWriteBuffer(RPL_MYINFO(client.getNickname(), std::string(SERVER_NAME), std::string(VERSION), std::string(USER_MODES), std::string(CHANNEL_MODES)));
    this->sendMotd(client);

    client.setState(Registered);
}