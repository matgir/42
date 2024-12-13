/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:05:03 by Helene            #+#    #+#             */
/*   Updated: 2024/11/22 17:07:04 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/irc.hpp"
#include "../../../includes/commands.hpp"
#include "../../../includes/Client.hpp"
#include "../../../includes/Server.hpp"

/*
If a JOIN is successful, the user is then sent the channel's topic
   (using RPL_TOPIC) and the list of users who are on the channel (using
   RPL_NAMREPLY), which must include the user joining.
*/
static void    joinRpl(Client &client, Channel &channel)
{
    // A JOIN message with the client as the message <source> and the channel they have 
    //  joined as the first parameter of the message.
    // std:: cout << channel.getFounder() << " is the founder of the channel\n"; //debugmg
    client.addToWriteBuffer(client.getUserID() + " JOIN " + channel.getName() + CRLF);
    
    if (!channel.getTopic().empty())
        client.addToWriteBuffer(RPL_TOPIC(client.getNickname(), channel.getName(), channel.getTopic()));
    
    std::stringstream ss;
    std::string prefix;
    ss << RPL_NAMREPLY(client.getNickname(), "=", channel.getName());
    for (std::map<std::string, Client*>::iterator it = channel.getAllMembers().begin(); it != channel.getAllMembers().end(); it++)
    {
        prefix = getPrefix(client, channel);
        if (it != channel.getAllMembers().begin() && *(it->second) != client)
            ss << " "; // sépare chaque client par un espace
        ss << prefix << it->first;
    }
    ss << CRLF;
    client.addToWriteBuffer(ss.str());
    client.addToWriteBuffer(RPL_ENDOFNAMES(client.getNickname(), channel.getName()));
}

/*
Check : Does the channel exist 
        -> If not, creates it. the client is now the channel operator
        -> If it does :
            Is it an invite only channel
            Does this channel require a password
            Is the channel's user's limit reached yet ?
*/
void    joinChannel(CommandContext &ctx, std::string const& channelName, std::string const& key)
{
    Channel *channel = ctx._server.getChannel(channelName);
    if (!channel)
    {
        Channel newChannel(channelName, &ctx._client);
        ctx._server.addChannel(newChannel, channelName);
        joinRpl(ctx._client, newChannel);
        return ;
    }
    
    // if (channel->isInvited(ctx._client.getNickname()))
        // channel->addInvitedUser(ctx._client.getNickname()); // commente, verifier que change r
    if (channel->isFull())
        ctx._client.addToWriteBuffer(ERR_CHANNELISFULL(ctx._client.getNickname(), channelName));
    else if (channel->getInviteOnlyMode() && !channel->isInvited(ctx._client.getNickname()))
        ctx._client.addToWriteBuffer(ERR_INVITEONLYCHAN(ctx._client.getNickname(), channelName));
    else if (channel->getPasswordMode() && (key.empty() || key != channel->getPassword()))
    /* ###################### check comment la commande join recois le password */
        ctx._client.addToWriteBuffer(ERR_BADCHANNELKEY(ctx._client.getNickname(), channelName));
    else
    {
        channel->addMember(&ctx._client);
        joinRpl(ctx._client, *channel);
        channel->sendToAll(ctx._client.getNickname(), ctx._client.getUserID() + " JOIN " + channel->getName() + CRLF);
        if (channel->isInvited(ctx._client.getNickname()))
            channel->removeInvitedUser(ctx._client.getNickname());
    }
}

void    parseParameters(std::vector<std::string> &params, std::vector<std::string> &channels,
        std::vector<std::string> &keys)
{
    // les channels et keys sont séparées par un ','
    // ex : JOIN #foo,&bar fubar 

    std::stringstream ss(params[0]);
    std::string buffer;

    while (getline(ss, buffer, ','))
        channels.push_back(buffer);
    
    if (params.size() >= 2)
    {
        ss.str(params[1]);
        while (getline(ss, buffer, ','))
            keys.push_back(buffer);
    }

}

void    cmdJoin(CommandContext &ctx)
{
    std::vector<std::string> params = ctx._parameters;
    if (params.empty() || params.size() < 1)
    {
        ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), ctx.getCommand()));
        return ;
    }

    std::vector<std::string> channels;
    std::vector<std::string> keys;
    parseParameters(params, channels, keys);
    size_t j = 0;
    for (size_t i = 0; i < channels.size(); i++)
    {
        // std::cout << channels[i]. //debug
        if (!checkChanMask(channels[i]))
        {
            ctx._client.addToWriteBuffer(ERR_BADCHANMASK(channels[i]));
            if (j < keys.size())
                j++;
            continue;
        }
        if (j < keys.size())
        {
            joinChannel(ctx, channels[i], keys[j]); // checker si une erreur pour l'un des channels fait que l'on arrete de checker pour les suivants
            j++;   
        }
        else
            joinChannel(ctx, channels[i], "");
    }
}