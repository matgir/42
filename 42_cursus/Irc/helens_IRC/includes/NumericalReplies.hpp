/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumericalReplies.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:03:14 by Helene            #+#    #+#             */
/*   Updated: 2024/12/18 12:06:56 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*
Most messages sent from a client to a server generate a reply of some sort. 
The most common form of reply is the numeric reply, used for both errors and normal replies. 
Distinct from a normal message, a numeric reply MUST contain a <source> and use a three-digit 
numeric as the command. 
A numeric reply SHOULD contain the target of the reply as the first parameter of the message. 
A numeric reply is not allowed to originate from a client.
*/

// dynamic macros for server 'command responses' (RPL_...) and error replies (ERR_...)

# define SERVER_NAME "LadyGaga"
# define VERSION    "13.12"
# define USER_MODES "No user modes available"
# define CHANNEL_MODES "itkol"
# define DEPARTURE_REASON "Leaving, bye bye"
# define ERROR_DEPARTURE "Suddenly disconnected"
# define DEFAULT_KICK_REASON "N'aime pas les coquillettes"

# define userID(nick, user, host) (nick + "!" + user + "@localhost") //  + host

/* -------------------------- Numerics : Replies ------------------------------- */

# define RPL_WELCOME(client, server, nick, user, host) (": 001 " + client + " :Welcome to the " + server + " Network " + userID(nick, user, host) + CRLF)
# define RPL_YOURHOST(client, server, version) (": 002 " + client + " :Your host is " + server + ", running on version " + version + CRLF)
# define RPL_CREATED(client, date) (": 003 " + client + " :This server was created " + date + CRLF)
# define RPL_MYINFO(client, server, version, userModes, channelModes) (": 004 " + client + " " + server + " " + version + ". " + userModes + ". Available channel modes : " + channelModes + CRLF) // "<servername> <version> <available user modes> <available channel modes>"
# define RPL_CHANNELMODEIS(client, channel, activeMode, kParams, lParams) (": 324 " + client + " " + channel + " " + activeMode + kParams + lParams + CRLF ) // pas compris si mode_string etait celui de la commande MODE, ou les current channel modes du channel en question ? 
# define RPL_NOTOPIC(client, channel) (":331 " + client + " " + channel + " :No topic is set" + CRLF)
# define RPL_TOPIC(client, channel, topic) (": 332 " + client + " " + channel + " :" + topic + CRLF)
# define RPL_INVITING(client, nick, channel) (": 341 " + client + " " + nick + " " + channel + CRLF)
# define RPL_NAMREPLY(client, symbol, channel) (": 353 " + client + " " + symbol + " " + channel + " :") // [prefix]<nick>{ [prefix]<nick>}, <prefix> is the highest channel membership prefix that client has in the channel, if they have one
# define RPL_ENDOFNAMES(client, channel) (": 366 " + client + " " + channel + " :End of /NAMES list" + CRLF)
# define RPL_MOTD(client, line) (": 372 " + client + " :" + line + CRLF)
# define RPL_MOTDSTART(client, server) (": 375 " + client + " :- " + server + " Message of the day - " + CRLF)
# define RPL_ENFODMOTD(client) (": 376 " + client + " :End of /MOTD command." + CRLF)

# define RPL_MODEMSG(source, channelName, modeParams) (source + " MODE " + channelName + " " + modeParams + CRLF)
# define ERROR_RPL(reason) ("Error :" + reason + CRLF)
# define QUIT_RPL(source, reason) (source + " QUIT :" + reason + CRLF)

// # define RPL_TIME(client, server, time) (": 391 " + client + " " + server + " :" + time + CRLF) // vérifier le format du message
// # define RPL_YOUREOPER(client) (": 381 " + client + " :You are now an IRC operator" + CRLF)

/* -------------------------- Numerics : Errors ------------------------------- */

# define ERR_NOSUCHNICK(client, nickname) (": 401 " + client + " " + nickname + " :No such nick/channel" + CRLF)
# define ERR_NOSUCHCHANNEL(client, channel) (": 403 " + client + " " + channel + " :No such channel" + CRLF)
# define ERR_NORECIPIENT(client, command) (": 411 " + client + " :No recipient given ("+ command +")" + CRLF)
# define ERR_NOTEXTTOSEND(client) (": 412 " + client + " :No text to send" + CRLF)
# define ERR_UNKNOWNCOMMAND(client, command) (": 421 " + client + " " + command + " :Unknown command" + CRLF)
# define ERR_NOMOTD(client) (": 422 " + client + " :MOTD file is missing" + CRLF)
# define ERR_NONICKNAMEGIVEN(client) (": 431 " + client + " :No nickname given" + CRLF)
# define ERR_ERRONEUSNICKNAME(client, nick) (": 432 " + client + " " + nick + " :Erroneus nickname" + CRLF)
# define ERR_NICKNAMEINUSE(client, nick) (": 433 " + client + " " + nick + " :Nickname is already in use" + CRLF)
# define ERR_USERNOTINCHANNEL(client, nick, channel) (": 441 " + client + " " + nick + " " + channel + " :They aren't on that channel" + CRLF)
# define ERR_NOTONCHANNEL(client, channel) (": 442 " + client + " " + channel + " :You're not on that channel" + CRLF)
# define ERR_USERONCHANNEL(client, nick, channel) (": 443 " + client + " " + nick + " " + channel + " :is already on channel" + CRLF)
# define ERR_NEEDMOREPARAMS(client, command) (": 461 " + client + " " + command + " :Not enough parameters" + CRLF)
# define ERR_ALREADYREGISTERED(client) (": 462 " + client + " :You may not reregister" + CRLF) 
# define ERR_PASSWDMISMATCH(client) (": 464 " + client + " :Password incorrect" + CRLF)
# define ERR_CHANNELISFULL(client, channel) (": 471 " + client + " " + channel + " :Cannot join channel (+l)" + CRLF)
# define ERR_UNKNOWNMODE(client, mode) (": 472 " + client + " " + mode + " :is unknown mode char to me" CRLF)
# define ERR_INVITEONLYCHAN(client, channel) (": 473 " + client + " " + channel + " :Cannot join channel (+i)" + CRLF)
# define ERR_BADCHANNELKEY(client, channel) (": 475 " + client + " " + channel + " :Cannot join channel (+k)" + CRLF)
# define ERR_BADCHANMASK(channel) (": 476 " + channel + " :Bad Channel Mask" + CRLF)
# define ERR_CHANOPRIVSNEEDED(client, channel) (": 482 " + client + " " + channel + " :You're not channel operator" + CRLF)

# define ERR_ALREADYJOINED(client, channel) (client + " : cannot join " + channel + " : already on channel" + CRLF)
