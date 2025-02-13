/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:55:46 by Helene            #+#    #+#             */
/*   Updated: 2024/12/18 14:15:52 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/irc.hpp"
#include "../../../includes/commands.hpp"
#include "../../../includes/Client.hpp"
#include "../../../includes/Server.hpp"

static bool validChar(char c)
{
    return (c == '[' || c == ']' || c == '{' || c == '}' 
        || c == '\\' || c == '|');
}

/*
Servers MUST allow at least all alphanumerical characters, square and curly brackets ([]{}), 
backslashes (\), and pipe (|) characters in nicknames, and MAY disallow digits as the first character. 
Servers MAY allow extra characters, as long as they do not introduce ambiguity in other commands, including:
    no leading # character or other character advertized in CHANTYPES
    no leading colon (:)
    no ASCII space
*/
static bool    validNick(std::string const& s)
{
    std::string::const_iterator it = s.begin();

    if (s.empty() || s.size() > 9)
        return false;
    
    if (!std::isalpha(*it) && !validChar(*it))
        return false;
    it++;
    for (std::string::const_iterator itt = it; itt != s.end(); itt++)
    {
        if (! (std::isalnum(*itt) || validChar(*itt) || *itt == '-')) 
            return false;
    }
    return true;
}

/*
Fonctions check a coder :
    - si le nick n'est pas deja utilisé dans le network
    - si le nick contient bien uniquement des caracteres valides

Nicknames are non-empty strings with the following restrictions:

    They MUST NOT contain any of the following characters: space (' ', 0x20), comma (',', 0x2C), asterisk ('*', 0x2A), 
        question mark ('?', 0x3F), exclamation mark ('!', 0x21), at sign ('@', 0x40).
    They MUST NOT start with any of the following characters: dollar ('$', 0x24), colon (':', 0x3A).
    They MUST NOT start with a character listed as a channel type (# OR &), channel membership prefix (@, % OR +), or prefix listed in the IRCv3 multi-prefix Extension.
    They SHOULD NOT contain any dot character ('.', 0x2E).

This command can be used at two times – during initial connection registration to set the client’s 
initial nickname, and after registration to change their nick. 
When used during registration, the server will silently accept the user’s request 
(or reply with an appropriate error numeric). 
If used after registration, the server will return a NICK message or appropriate error numerics.

The NICK message may be sent from the server to clients to acknowledge their NICK command was successful,
and to inform other clients about the change of nickname. In these cases, the <source> of the message 
will be the old nickname [ [ "!" user ] "@" host ] of the user who is changing their nickname.

*/
void    cmdNick(CommandContext &ctx)
{
    if (ctx._parameters.empty())
    {
        ctx._client.addToWriteBuffer(ERR_NONICKNAMEGIVEN(ctx._client.getNickname())); 
        return ;
    }
    
    std::string nickname = ctx._parameters[0];
    if (!validNick(nickname))
    {
        ctx._client.addToWriteBuffer(ERR_ERRONEUSNICKNAME(ctx._client.getNickname(), nickname));
        return ;
    }
    if (ctx._server.nickInUse(nickname))
    {
        ctx._client.addToWriteBuffer(ERR_NICKNAMEINUSE(ctx._client.getNickname(), nickname));
        return ;
    }
    
    std::string oldNick = ctx._client.getNickname();
    ctx._client.setNickname(nickname);
    
    // if client had not provided a nickname before
    if (!ctx._client.checkState(Nick) && !ctx._client.checkState(Registered))
    {
        ctx._client.addState(Nick);
        if (ctx._client.checkState(Registering)) // a rentre NICK et USER
            ctx._server.tryLogin(ctx._client);
    }
    else
    {
        std::stringstream ss;
        std::string oldUserID = userID(oldNick, ctx._client.getUsername(), ctx._client.getHostname());
        ss << ":" << oldUserID << " NICK " << nickname + CRLF;
        ctx._client.addToWriteBuffer(ss.str());
        ctx._server.InformOthers(ctx._client, ":" + oldUserID, "NICK " + nickname);
        ctx._server.updateNick(oldNick, nickname); // met a jour le nick dans tous les channels dans lesquels est le client 
        
    }
} 