/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumericalReplies.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:03:14 by Helene            #+#    #+#             */
/*   Updated: 2024/10/27 17:42:09 by Helene           ###   ########.fr       */
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
# define USER_MODES " a remplir "
# define CHANNEL_MODES " a remplir "
# define DEPARTURE_REASON "A bas l'etat"

# define userID(nick, user, host) (nick + "!" + user + "@" + host)

# define ERR_UNKNOWNCOMMAND(command) (": 421 " + command + " :Unknown command" + CRLF)
# define ERROR_RPL(reason) ("Error :" + reason + CRLF)
# define QUIT_RPL(nick, user, host, reason) (":" + userID(nick, user, host) + " QUIT :" + reason + CRLF)

# define RPL_WELCOME(client, nick, user, host) (": 001 " + client + " :Welcome to the Internet Relay Network " + userID(nick, user, host) + CRLF)
# define RPL_YOURHOST(client, server, version) (": 002 " + client + " :Your host is " + server + ", running on version " + version + CRLF)
# define RPL_CREATED(client, date) (": 003 " + client + " :This server was created " + date + CRLF)
# define RPL_MYINFO(client, server, version, userModes, channelModes) (": 004 " + client + " :" + server + ", version " + version + ". Available user modes : " + userModes + ". Available channel modes : " + channelModes + CRLF) // "<servername> <version> <available user modes> <available channel modes>"
# define RPL_MOTDSTART(client, server) (": 375 " + client + " :- " + server + " Message of the day -" + CRLF)
# define RPL_MOTD(client, line) (": 372 " + client + " :- " + line + CRLF)
# define RPL_ENFODMOTD(client) (": 376 " + client + " :End of MOTD command" + CRLF)


/* -------------------------- Command responses & Error replies ------------------------------- */

# define ERR_NEEDMOREPARAMS(client, command) (": 461 " + client + " " + command + " :Not enough parameters" + CRLF)
# define ERR_ALREADYREGISTERED(client) (": 462 " + client + " :You may not reregister" + CRLF) // 462
# define ERR_PASSWDMISMATCH(client) (": 464 " + client + " :Password incorrect" + CRLF) // 464

// NICK
# define ERR_NONICKNAMEGIVEN(client) (": 431 " + client + " :No nickname given" + CRLF)
# define ERR_ERRONEUSNICKNAME(client, nick) (": 432 " + client + " " + nick + " :Erroneus nickname" + CRLF)
# define ERR_NICKNAMEINUSE(client, nick) (": 433 " + client + " " + nick + " :Nickname is already in use" + CRLF)

// OPER
#define RPL_YOUREOPER(client) (": 381 " + client + " :You are now an IRC operator" + CRLF)

// JOIN
# define ERR_NOSUCHCHANNEL(client, channel) (": 403 " + client + " " + channel + " :No such channel" + CRLF)
# define ERR_TOOMANYCHANNELS(client, channel) (": 405 " + client + " " + channel + " :You have joined too many channels" + CRLF)
# define ERR_BADCHANNELKEY(client, channel) (": 475 " + client + " " + channel + " :Cannot join channel (+k)" + CRLF)
# define ERR_BANNEDFROMCHAN(client, channel) (": 474 " + client + " " + channel + " :Cannot join channel (+b)" + CRLF)  // doit pas gérer MODE +b, si ?
# define ERR_CHANNELISFULL(client, channel) (": 471 " + client + " " + channel + " :Channel is full (+l)" + CRLF)
# define ERR_INVITEONLYCHAN(client, channel) (": 473 " + client + " " + channel + " :Cannot join channel (+i)" + CRLF)
# define ERR_BADCHANMASK(channel) (": 476 " + channel + " :Bad Channel Mask" + CRLF)

# define RPL_TOPIC(client, channel, topic) (": 332 " + client + " " + channel + " :" + topic + CRLF)
# define RPL_TOPICWHOTIME(client, channel, nick, setat) (": 333 " + client + " " + channel + " " + nick + " " + setat + CRLF)
// # define RPL_NAMREPLY(channel) (": 353   " + channel " :") // [prefix]<nick>{ [prefix]<nick>}, <prefix> is the highest channel membership prefix that client has in the channel, if they have one
# define RPL_NAMREPLY(client, symbol, channel) (": 353 " + client + " " + symbol + " " + channel + " :")
# define RPL_ENDOFNAMES(client, channel) (": 366 " + client + " " + channel + " :End of /NAMES list" + CRLF)


// TOPIC 
/*  ERR_NEEDMOREPARAMS (461)
    ERR_NOSUCHCHANNEL (403)
    ERR_NOTONCHANNEL (442)
    ERR_CHANOPRIVSNEEDED (482)
    RPL_NOTOPIC (331)
    RPL_TOPIC (332)
    RPL_TOPICWHOTIME (333) */
# define ERR_NOTONCHANNEL(client, channel) (": 442 " + client + " " + channel + " :You're not on that channel" + CRLF)
# define ERR_CHANOPRIVSNEEDED(client, channel) (": 482 " + client + " " + channel + " :You're not channel operator" + CRLF)
# define RPL_NOTOPIC(client, channel) (":331 " + client + " " + channel + " :No topic is set" + CRLF)

// NAMES
/*  RPL_NAMREPLY (353)
    RPL_ENDOFNAMES (366) */

// LIST -> implementer ces RPL avec des macros est impossible 
/*  RPL_LISTSTART (321)
    RPL_LIST (322)
    RPL_LISTEND (323) */

// INVITE
/*  RPL_INVITING (341)
    ERR_NEEDMOREPARAMS (461)
    ERR_NOSUCHCHANNEL (403)
    ERR_NOTONCHANNEL (442)
    ERR_CHANOPRIVSNEEDED (482)
    ERR_USERONCHANNEL (443) */
# define RPL_INVITING(client, nick, channel) (": 341 " + client + " " + nick + " " + channel + CRLF)
# define ERR_USERONCHANNEL(client, nick, channel) (": 443 " + client + " " + nick + " " + channel + " :is already on channel" + CRLF)

// KICK
/*  ERR_NEEDMOREPARAMS (461)
    ERR_NOSUCHCHANNEL (403)
    ERR_CHANOPRIVSNEEDED (482)
    ERR_USERNOTINCHANNEL (441)
    ERR_NOTONCHANNEL (442) */
# define ERR_USERNOTINCHANNEL(client, nick, channel) (": 442 " + client + " " + nick + " " + channel + " :They aren't on that channel" + CRLF)

// MOTD ?
/*  ERR_NOSUCHSERVER (402)
    ERR_NOMOTD (422)
    RPL_MOTDSTART (375)
    RPL_MOTD (372)
    RPL_ENDOFMOTD (376) */
# define ERR_NOMOTD(client) (": 422 " + client + " :MOTD file is missing" + CRLF)
// # define ERR_NOSUCHSERVER(client, server_name) (": 402 " + client + " " + server_name + " :No such server" + CRLF)

// VERSION ?

// ADMIN ?

// TIME ?
/*  ERR_NOSUCHSERVER (402)
    RPL_TIME (391) */
# define RPL_TIME(client, server, time) (": 391 " + client + " " + server + " :" + time + CRLF) // vérifier le format du message

// STATS ?

// HELP
/*  ERR_HELPNOTFOUND (524)
    RPL_HELPSTART (704)
    RPL_HELPTXT (705)
    RPL_ENDOFHELP (706) */
# define ERR_HELPNOTFOUND(client, subject) (": 524 " + client + " " + subject + " :No help available on this topic" + CRLF)
# define RPL_HELPSTART(client, subject, first_line) (": 704 " + client + " " + subject + " :" + first_line + CRLF)
# define RPL_HELPTXT(client, subject, line) (": 705 " + client + " " + subject + " :" + line + CRLF)
# define RPL_ENDOFHELP(client, subject, last_line) (":  " + client + " " + subject + " :" + last_line + CRLF)

// INFO 
/*  RPL_INFO (371)
    RPL_ENDOFINFO (374) */
# define RPL_INFO(client, info) (": 371 " + client + " :" + info + CRLF)
# define RPL_ENDOFINFO(client) (": 374 " + client + " :End of INFO list" + CRLF)

// MODE
/*  // User mode
    ERR_NOSUCHNICK (401)
    ERR_USERSDONTMATCH (502)
    RPL_UMODEIS (221)
    ERR_UMODEUNKNOWNFLAG (501)
    // Channel mode
    ERR_NOSUCHCHANNEL (403)
    RPL_CHANNELMODEIS (324), may be followed by RPL_CREATIONTIME (329)
    ERR_CHANOPRIVSNEEDED (482) */
# define ERR_NOSUCHNICK(client, nickname) (": 401 " + client + " " + nickname + " :No such nick/channel" + CRLF)
# define ERR_USERSDONTMATCH(client) (": 502 " + client + " :Can't change mode for other users" + CRLF)
# define RPL_UMODEIS(client, user_modes) (": 221 " + client + " " + user_modes + CRLF)
# define ERR_UMODEUNKNOWNFLAG(client) (": 501 " + client + " :Unknown MODE flag" + CRLF) // préciser le flag ?
# define RPL_CHANNELMODEIS(client, channel, channel_string, mode_arguments) // pas compris si mode_string etait celui de la commande MODE, ou les current channel modes du channel en question ? 




// (":  " + client + " " + subject + " :" + CRLF)
