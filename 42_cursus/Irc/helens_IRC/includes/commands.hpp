/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:46:42 by Helene            #+#    #+#             */
/*   Updated: 2024/11/02 15:50:28 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "irc.hpp"
#include "CommandContext.hpp"
#include "NumericalReplies.hpp"

# define DEFAULT_KICK_REASON "vote rn"

class Channel;

void    cmdPass(CommandContext &ctx);
void    cmdUser(CommandContext &ctx);
void    cmdNick(CommandContext &ctx);
void    cmdMotd(CommandContext &ctx);
void    cmdPing(CommandContext &ctx);
void    cmdQuit(CommandContext &ctx);
void    cmdJoin(CommandContext &ctx);
void    cmdPart(CommandContext &ctx);
void	cmdPrivmsg(CommandContext &ctx);

void    cmdMode(CommandContext &ctx);
void    cmdInvite(CommandContext &ctx);
void    cmdKick(CommandContext &ctx);
void    cmdTopic(CommandContext &ctx);

/* ---------- Utils ---------- */

std::string getPrefix(Client &client, Channel &channel);
bool        checkChanMask(std::string const& chanName);