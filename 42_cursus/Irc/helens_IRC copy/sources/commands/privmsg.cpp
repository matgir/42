/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:17:33 by hepompid          #+#    #+#             */
/*   Updated: 2024/12/18 13:26:53 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/irc.hpp"
#include "../../includes/commands.hpp"
#include "../../includes/Client.hpp"
#include "../../includes/Server.hpp"

static std::string getFinalText(CommandContext &ctx, std::string const& text, std::string target)
{
    std::stringstream ss;
    ss << ctx._client.getUserID();
    ss << " PRIVMSG " << target << " :" << text << CRLF;
    
    return ss.str();   
}

/*
Command: PRIVMSG
  Parameters: <target>{,<target>} <text to be sent>

The PRIVMSG message is sent from the server to client to deliver a message to that client. 
The <source> of the message represents the user or server that sent the message, 
    and the <target> represents the target of that PRIVMSG (which may be the client, a channel, etc).

When the PRIVMSG message is sent from a server to a client and <target> starts with a 
    dollar character ('$', 0x24), the message is a broadcast sent to all clients on one or multiple servers.
*/

/*
If <target> is a channel name, it may be prefixed with one or more channel membership 
    prefix character (@, +, etc) and the message will be delivered only to the members 
    of that channel with the given or higher status in the channel.
*/
void    msgToChannel(CommandContext& ctx)
{
    std::vector<std::string> params = ctx._parameters;
    std::string target = params[0];
    std::string text = params[1];
    
    bool operators = false;
    for (std::string::iterator it = target.begin(); it != target.end() && *it != '#'; it++)
    {
        if (*it == '@')
            operators = true;
    }
    
    std::string channelName = std::string(target.begin() + target.find('#'), target.end());
    Channel *channel = ctx._server.getChannel(channelName);
    if (!channel)
    {
        ctx._client.addToWriteBuffer(ERR_NOSUCHCHANNEL(ctx._client.getNickname(), channelName));
        return ;
    }
    else if (!channel->isMember(ctx._client.getNickname()))
    {
        ctx._client.addToWriteBuffer(ERR_NOTONCHANNEL(ctx._client.getNickname(), channelName));
        return;
    }

    if (operators)
        channel->sendToOperators(ctx._client.getNickname(), getFinalText(ctx, text, channelName));
    else
        channel->sendToAll(ctx._client.getNickname(), getFinalText(ctx, text, channelName));
}

void    msgToClient(CommandContext& ctx)
{
    std::vector<std::string> params = ctx._parameters;
    std::string target = params[0];
    std::string text = params[1];
    
    Client *recipient = ctx._server.getClientByNick(target);
    if (!recipient)
    {
        ctx._client.addToWriteBuffer(ERR_NOSUCHNICK(ctx._client.getNickname(), target));
        return ;
    }
    recipient->addToWriteBuffer(getFinalText(ctx, text, target));
}

void    cmdPrivmsg(CommandContext& ctx)
{
   if (ctx._parameters.empty())
        ctx._client.addToWriteBuffer(ERR_NORECIPIENT(ctx._client.getNickname(), ctx._command));
    else if (ctx._parameters.size() < 2)
        ctx._client.addToWriteBuffer(ERR_NOTEXTTOSEND(ctx._client.getNickname()));
    else 
    {
        
        if (ctx._parameters[0].find('#') != std::string::npos)
            msgToChannel(ctx);
        else
            msgToClient(ctx);
    }
}
