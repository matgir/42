/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:09:33 by Helene            #+#    #+#             */
/*   Updated: 2024/11/22 14:59:13 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/irc.hpp"
#include "../../../includes/commands.hpp"
#include "../../../includes/Client.hpp"
#include "../../../includes/Server.hpp"

/*
Parameters: <nickname> <channel>

The INVITE message is used to invite users to a channel.  The
   parameter <nickname> is the nickname of the person to be invited to
   the target channel <channel>.  There is no requirement that the
   channel the target user is being invited to must exist or be a valid
   channel.  To invite a user to a channel which is invite only (MODE
   +i), the client sending the invite must be recognised as being a
   channel operator on the given channel.

   Numeric Replies:
    ERR_NEEDMOREPARAMS              ERR_NOSUCHNICK
    ERR_NOTONCHANNEL                ERR_USERONCHANNEL
    ERR_CHANOPRIVSNEEDED
    
    RPL_INVITING                    RPL_AWAY
*/

void    cmdInvite(CommandContext &ctx)
{
    std::vector<std::string> params = ctx._parameters;
    if (params.empty() || params.size() < 2)
    {
        ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), ctx.getCommand()));
        return ;
    }

    // vérifier l'ordre des checks
    // ERR_BADCHANMASK aussi ? 
    std::string nickToInvite = ctx._parameters[0];
    std::string channelName = ctx._parameters[1];
    Channel *channel = ctx._server.getChannel(channelName);
    
    if (!channel)
        ctx._client.addToWriteBuffer(ERR_NOSUCHCHANNEL(ctx._client.getNickname(), channelName));
    else if (!ctx._server.nickInUse(nickToInvite))
        ctx._client.addToWriteBuffer(ERR_NOSUCHNICK(ctx._client.getNickname(), nickToInvite));
    else if (!channel->isMember(ctx._client.getNickname()))
        ctx._client.addToWriteBuffer(ERR_NOTONCHANNEL(ctx._client.getNickname(), channelName));
    else if (channel->isMember(nickToInvite))
        ctx._client.addToWriteBuffer(ERR_USERONCHANNEL(ctx._client.getNickname(), ctx._client.getNickname(), channelName));
    else if (channel->getInviteOnlyMode() && !channel->isOperator(ctx._client.getNickname()))
        ctx._client.addToWriteBuffer(ERR_CHANOPRIVSNEEDED(ctx._client.getNickname(), channelName));
    else 
    {
        Client *invitedUser = ctx._server.getClientByNick(nickToInvite);
        if (!invitedUser)
            return ;
        if (channel->isInvited(nickToInvite)) // meaning the user is already on the invitedUsers list -> error/warning/info msg ?
            return ;
        channel->addInvitedUser(nickToInvite);
       
        ctx._client.addToWriteBuffer(RPL_INVITING(ctx._client.getNickname(), nickToInvite, channelName)); // vérifier les arguments, parait chelou
        
        // invited user must receive : :lnnn!hlesny@127.0.0.1 INVITE lnick #test42 (ie :<userID> INVITE <userNick> <channelName)
        std::stringstream ss;
        ss << ctx._client.getUserID() << " INVITE " << nickToInvite << " " << channelName << CRLF; 
        invitedUser->addToWriteBuffer(ss.str());
    }

    // check if channel exists : if not, ERR_NOSUCHCHANNEL
    // check if the user inviting the other user is on that channel. if not, ERR_NOTONCHANNEL
    // check if the nickname given as parameter exists. if not, ERR_NOSUCHNICK
    // check if the invited user is already in the channel. if it is, ERR_USERONCHANNEL
    // if channel is invite-only, check if client inviting the other user is operator
    // -> if not, ERR_CHANOPRIVSNEEDED
    // if invite is successful : RPL_INVITING
}