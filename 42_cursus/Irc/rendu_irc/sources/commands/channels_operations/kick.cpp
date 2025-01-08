/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:13:19 by Helene            #+#    #+#             */
/*   Updated: 2024/12/18 13:11:34 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/irc.hpp"
#include "../../../includes/commands.hpp"
#include "../../../includes/Client.hpp"
#include "../../../includes/Server.hpp"

/*
Parameters: <channel> <user> *( "," <user> ) [<comment>] (modern.ircdocs.horse)
            ou <channel>{,<channel>} <user>{,<user>} [<comment>] (rfc 1459) ?

If no comment is given, the server SHOULD use a default message instead.
Servers MUST NOT send multiple users in this message to clients, and MUST distribute 
    these multiple-user KICK messages as a series of messages with a single user name on each.
    If a KICK message is distributed in this way, <comment> (if it exists) 
    should be on each of these messages.

Checks performed :
    - check if channel exists : ERR_NOSUCHCHANNEL
    - check if the client issuing the kick command is not in the channel : ERR_NOTONCHANNEL
    - check if client issuing the kick command is channel op : ERR_CHANOPRIVSNEEDED
    - check if user to be kicked is in given channel : ERR_USERNOTINCHANNEL
*/

void    cmdKick(CommandContext &ctx)
{
    std::vector<std::string> params = ctx._parameters;
    if (params.empty() || params.size() < 2)
    {
        ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), ctx.getCommand()));
        return ;
    }

    std::string channelName = params[0];
    std::string user = params[1];
    std::string comment = params.size() > 2 ? params[2] : DEFAULT_KICK_REASON;
    Channel *channel = ctx._server.getChannel(channelName);
    
    if (!channel)
        ctx._client.addToWriteBuffer(ERR_NOSUCHCHANNEL(ctx._client.getNickname(), channelName));
    else if (!channel->isMember(ctx._client.getNickname()))
        ctx._client.addToWriteBuffer(ERR_NOTONCHANNEL(ctx._client.getNickname(), channelName));
    else if (!channel->isOperator(ctx._client.getNickname()))
        ctx._client.addToWriteBuffer(ERR_CHANOPRIVSNEEDED(ctx._client.getNickname(), channelName));
    else if (!channel->isMember(user))
        ctx._client.addToWriteBuffer(ERR_USERNOTINCHANNEL(ctx._client.getNickname(), user, channelName));
    else
    {
        std::stringstream ss;
        ss << ctx._client.getUserID() << " KICK " << channelName << " " << user << " : " << comment << CRLF; 
                
        Client *target = ctx._server.getClientByNick(user);
        if (!target)
            return ;
        channel->sendToAll(user, ss.str(), false);
        target->removeChannel(channel->getName());
        channel->removeMember(user); // remove user from channel's registry 
        
        // in case the only user in that channel kicked itself out 
        if (channel->isEmpty())
        {
            ctx._server.removeChannel(channel->getName());
            ctx._server._log(DEBUG, "Removing channel " + channel->getName());
        }
    }
}
