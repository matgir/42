/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:04:38 by Helene            #+#    #+#             */
/*   Updated: 2024/10/27 22:17:21 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/irc.hpp"
#include "../../../includes/commands.hpp"
#include "../../../includes/Client.hpp"
#include "../../../includes/Server.hpp"

/* 
Parameters: <channel> [<topic>]

The TOPIC message is used to change or view the topic of a channel.
   The topic for channel <channel> is returned if there is no <topic>
   given.  If the <topic> parameter is present, the topic for that
   channel will be changed, if the channel modes permit this action.

If the topic of a channel is changed or cleared, every client in that channel 
    (including the author of the topic change) will receive a TOPIC command 
    with the new topic as argument (or an empty argument if the topic was 
    cleared) alerting them to how the topic has changed. 
    If the <topic> param is provided but the same as the previous topic 
    (ie. it is unchanged), servers MAY notify the author and/or other users anyway.

Numeric Replies:
    ERR_NEEDMOREPARAMS              ERR_NOTONCHANNEL
    ERR_CHANOPRIVSNEEDED
    RPL_NOTOPIC                     RPL_TOPIC
*/

void    cmdTopic(CommandContext &ctx)
{
    std::vector<std::string> params = ctx._parameters;
    if (params.empty() || params.size() < 1)
    {
        ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), ctx.getCommand()));
        return ;
    }
    
    std::string channelName = params[0];
    bool topic = (params.size() > 1);
    Channel *channel = ctx._server.getChannel(channelName);

    if (!channel)
        ctx._client.addToWriteBuffer(ERR_NOSUCHCHANNEL(ctx._client.getNickname(), channelName));
    else if (!channel->isMember(ctx._client.getNickname()))
        ctx._client.addToWriteBuffer(ERR_NOTONCHANNEL(ctx._client.getNickname(), channelName));
    else if (channel->getTopicRestrictionMode() && !channel->isOperator(ctx._client.getNickname()))
        ctx._client.addToWriteBuffer(ERR_CHANOPRIVSNEEDED(ctx._client.getNickname(), channelName));
    else 
    {
        if (topic) // change current topic and inform users on that channel
        {
            std::string newTopic = params[1];
            channel->setTopic(newTopic);
            std::stringstream ss;
            ss << ctx._client.getUserID() << " TOPIC " << channelName << " : " << newTopic << CRLF;
            ctx._client.addToWriteBuffer(ss.str());
            channel->sendToAll(ctx._client.getNickname(), ss.str());
        }   
        else // view current topic
        {
            if (channel->hasTopic())
                ctx._client.addToWriteBuffer(RPL_TOPIC(ctx._client.getNickname(), channelName, channel->getTopic()));
            else
                ctx._client.addToWriteBuffer(RPL_NOTOPIC(ctx._client.getNickname(), channelName));
        }
    }
}