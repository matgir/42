/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:13:19 by Helene            #+#    #+#             */
/*   Updated: 2024/11/22 16:59:35 by hlesny           ###   ########.fr       */
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
*/

void    cmdKick(CommandContext &ctx)
{
    std::vector<std::string> params = ctx._parameters;
    if (params.empty() || params.size() < 2)
    {
        ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), ctx.getCommand()));
        return ;
    }

    // no need to check if the channel mask is valid ? (is marked as deprecated numeric reply on ircdocs.horse )

    std::string channelName = params[0];
    std::string user = params[1];
    std::string comment = params.size() > 2 ? params[2] : DEFAULT_KICK_REASON;
    Channel *channel = ctx._server.getChannel(channelName);
    std::cout << "entering kick command\nuser is " << user << '\n'; //debugmg
    
    if (!channel)
        ctx._client.addToWriteBuffer(ERR_NOSUCHCHANNEL(ctx._client.getNickname(), channelName));
    else if (!channel->isMember(ctx._client.getNickname()))
        ctx._client.addToWriteBuffer(ERR_NOTONCHANNEL(ctx._client.getNickname(), channelName));
    else if (!channel->isOperator(ctx._client.getNickname()))
        ctx._client.addToWriteBuffer(ERR_CHANOPRIVSNEEDED(ctx._client.getNickname(), channelName));
    else if (!channel->isMember(user))
        ctx._client.addToWriteBuffer(ERR_NOTONCHANNEL(user, channelName));
    else
    {
        std::stringstream ss;

        // ss << ctx._client.getUserID() << " KICK " << channelName << " " << ctx._client.getNickname() << " : " << comment << CRLF;
        ss << ctx._client.getUserID() << " KICK " << channelName << " " << user << " : " << comment << CRLF; //debugmg
        std::cout << ss.str() << '\n'; //debugmg
        channel->sendToAll(user, ss.str(), 0);
        
        // is it possible for a chanOp to kick another chanOp ?
        if (channel->isOperator(user))
            channel->removeOperator(user);
        else
            channel->removeMember(user);
        // in case the only user in that channel kicked itself out 
        if (channel->isEmpty())
            ctx._server.removeChannel(channelName); 

        /*
        This message may be sent from a server to a client to notify the client that 
            someone has been removed from a channel. 
        In this case, the message <source> will be the client who is being removed, 
            and <channel> will be the channel which that client has been removed from.
        
        -> send a part msg to all users from channel, when a client is being kicked out of that channel, additionnally from the KICK msg that 
            is already being broadcasted to entire channel ?
        ie : clientBeingKicked.ID + PART + channelName + reason (if exists)
        */
    }

    // check if channel exists : ERR_NOSUCHCHANNEL
    // check if the client issuing the kick command is not in the channel : ERR_NOTONCHANNEL
    // check if client issuing the kick command is channel op : ERR_CHANOPRIVSNEEDED
    // check if user to be kicked is in given channel : ERR_USERNOTINCHANNEL
}
