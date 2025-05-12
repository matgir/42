/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:26:00 by Helene            #+#    #+#             */
/*   Updated: 2024/12/18 13:12:47 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/irc.hpp"
#include "../../../includes/commands.hpp"
#include "../../../includes/Client.hpp"
#include "../../../includes/Server.hpp"

/* 
Parameters: <channel>{,<channel>} [<reason>]

This message may be sent from a server to a client to notify the client that someone 
has been removed from a channel. 
In this case, the message <source> will be the client who is being removed, 
and <channel> will be the channel which that client has been removed from.
*/

void    parseParameters_part(std::vector<std::string> &params, std::vector<std::string> &channels,
        std::vector<std::string> &keys)
{
    std::stringstream ss(params[0]);
    std::string buffer;

    while (getline(ss, buffer, ','))
        channels.push_back(buffer);
    if (params.size() >= 2)
    {
        buffer.clear();
        std::stringstream ss2(params[1]);
        while (std::getline(ss2, buffer, ','))
        {
            keys.push_back(buffer);
        }
    }

}

void    cmdPart(CommandContext &ctx)
{
    if (ctx._parameters.empty())
    {
        ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), ctx._command));
        return ;
    } 
    
    std::vector<std::string> keys;
    std::vector<std::string> channels;
    parseParameters_part(ctx._parameters, channels, keys);
    Channel *channel;
    std::stringstream msg;
    std::string reason = (ctx._parameters.size() >= 2) ? ctx._parameters[1] : ctx._client.getNickname();
    
    
    for (size_t i = 0; i < channels.size(); i++)
    {
        if (!ctx._server.channelExists(channels[i]))
            ctx._client.addToWriteBuffer(ERR_NOSUCHCHANNEL(ctx._client.getNickname(), channels[i]));
        else
        {
            channel = ctx._server.getChannel(channels[i]);
            if (!channel->isMember(ctx._client.getNickname()))
            {
                ctx._client.addToWriteBuffer(ERR_NOTONCHANNEL(ctx._client.getNickname(), channel->getName()));
                return ;
            }
            if (keys.empty())
                msg << ctx._client.getUserID() << " PART " << channels[i] << CRLF;
            else
                msg << ctx._client.getUserID() << " PART " << channels[i] << " :" << keys[i] << CRLF;
            ctx._client.addToWriteBuffer(msg.str());
            

            ctx._client.removeChannel(channels[i]); // remove channel's name from client's registry
            
            channel->removeMember(ctx._client.getNickname()); // remove user from channel's registry 
            
            channel->sendToAll(ctx._client.getNickname(), msg.str());
            if (channel->isEmpty())
            {
                ctx._server.removeChannel(channels[i]);
                ctx._server._log(DEBUG, "Removing channel " + channels[i]);
            }
                
        }
    }
}
    