/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:54:21 by Helene            #+#    #+#             */
/*   Updated: 2024/12/18 13:18:13 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/irc.hpp"
#include "../../../includes/commands.hpp"
#include "../../../includes/Client.hpp"
#include "../../../includes/Server.hpp"


/*
The USER command is used at the beginning of a connection to specify the username and realname of a new user.
Parameters: <username> <hostname> <servername> <realname>
*/
void    cmdUser(CommandContext &ctx)
{
    if (ctx._client.checkState(User) || ctx._client.checkState(Registered))
    {
        ctx._client.addToWriteBuffer(ERR_ALREADYREGISTERED(ctx._client.getNickname()));
        return ;
    }
    
    std::vector<std::string> params = ctx._parameters;
    if (params.empty() || params.size() < 4 || params[0].size() < 1 || params[3].empty()) // minimum length of username is 1 
    {
        ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), ctx._command));
        return ;
    }
    
    ctx._client.setUsername(params[0]);
    ctx._client.setHostname(params[2]);
    ctx._client.setRealname(params[3]);
    
    ctx._client.addState(User);
    if (ctx._client.checkState(Registering))
        ctx._server.tryLogin(ctx._client);
}