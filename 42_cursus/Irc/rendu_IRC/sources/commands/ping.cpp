/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:35:37 by Helene            #+#    #+#             */
/*   Updated: 2024/10/04 12:52:23 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/irc.hpp"
#include "../../includes/commands.hpp"
#include "../../includes/Client.hpp"
#include "../../includes/Server.hpp"

/*
Command: PING
  Parameters: <token>
When receiving a PING message, clients or servers must reply to it with a PONG message with the same <token> value.

The PONG command is used as a reply to PING commands, by both clients and servers. 
The <token> should be the same as the one in the PING message that triggered this PONG.
Servers MUST send a <server> parameter, and clients SHOULD ignore it. 
It exists for historical reasons, and indicates the name of the server sending the PONG. 
Clients MUST NOT send a <server> parameter.

RECV <127.0.0.1> 'PING localhost'
SEND <127.0.0.1> 'PONG :localhost'

*/
void    cmdPing(CommandContext &ctx)
{
    std::vector<std::string> params = ctx._parameters;
    if (params.empty())
    {
        ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), ctx._command));
        return ;
    }
    ctx._client.addToWriteBuffer("PONG :" + std::string(SERVER_NAME) + " " + params[0] + CRLF);
}