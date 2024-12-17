/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:54:21 by Helene            #+#    #+#             */
/*   Updated: 2024/12/17 16:28:28 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/irc.hpp"
#include "../../../includes/commands.hpp"
#include "../../../includes/Client.hpp"
#include "../../../includes/Server.hpp"


/*
The USER command is used at the beginning of a connection to specify the username and realname of a new user.
Parameters: <username> <hostname> <servername> <realname>
*/
void    cmdUser(CommandContext &ctx)
{
    if (ctx._client.checkState(User) || ctx._client.checkState(Registered))
    {
        ctx._client.addToWriteBuffer(ERR_ALREADYREGISTERED(ctx._client.getNickname()));
        return ;
    }
    
    std::vector<std::string> params = ctx._parameters;
    if (params.empty() || params.size() < 4 || params[0].size() < 2 || params[3].empty()) // minimum length of username is 1 
    {
        ctx._client.addToWriteBuffer(ERR_NEEDMOREPARAMS(ctx._client.getNickname(), ctx._command));
        return ;
    }
    
    /*
        The <mode> parameter should be a numeric, and can be used to
        automatically set user modes when registering with the server.  This
        parameter is a bitmask, with only 2 bits having any signification: if
        the bit 2 is set (if (mode & (1 << 2)) == 1 ), the user mode 'w' will be set and if the bit 3 is
        set, the user mode 'i' will be set.  (See Section 3.1.5 "User
        Modes").
    */
   //todo : juste appeler la commande MODE ?
    // int mode = atoi(params[1].c_str());
    // std::string modes;
    // if (mode & (1 << 3)) // ie si if (mode == 8)
        // modes += "i"; // ou "+i" ? 
    
    ctx._client.setUsername(params[0]);
    // ctx._client.addModes(modes);
    ctx._client.setHostname(params[2]); // ? -> ou met juste localhost ? 
    ctx._client.setRealname(params[3]);
    
    ctx._client.addState(User);
    if (ctx._client.checkState(Registering))
        ctx._server.tryLogin(ctx._client);
}