/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:46:03 by Helene            #+#    #+#             */
/*   Updated: 2024/10/27 14:17:21 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/irc.hpp"
#include "../../../includes/commands.hpp"
#include "../../../includes/Client.hpp"
#include "../../../includes/Server.hpp"

/*
The PASS command is used to set a ‘connection password’.
If set, the password must be set before any attempt to register the connection is made.
This requires that clients send a PASS command before sending the NICK / USER combination.
->  The PASS command is not required for the connection to be registered, but if included 
    it MUST precede the latter of the NICK and USER commands.

The password supplied must match the one defined in the server configuration.
It is possible to send multiple PASS commands before registering but only the last one sent 
is used for verification and it may not be changed once the client has been registered.

If the password supplied does not match the password expected by the server,
then the server SHOULD send ERR_PASSWDMISMATCH (464) and MAY then close the connection with ERROR. 
Servers MUST send at least one of these two messages.

Numeric replies:
    ERR_NEEDMOREPARAMS (461)
    ERR_ALREADYREGISTERED (462)
    ERR_PASSWDMISMATCH (464)
    
*/
void    cmdPass(CommandContext &ctx)
{
    if (ctx._client.checkState(Registering))
    {
        ctx._client.addToWriteBuffer(ERR_ALREADYREGISTERED(ctx._client.getNickname()));
        return ;
    }

    if (ctx._parameters.empty())
    {
        ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), ctx._command));
        return ;
    }

    std::vector<std::string> params = ctx._parameters;
    std::string passwd = params[0];
    
    ctx._client.setPassword(passwd);
}
