/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:24:51 by Helene            #+#    #+#             */
/*   Updated: 2024/12/17 11:24:43 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/irc.hpp"
#include "../../../includes/commands.hpp"
#include "../../../includes/Client.hpp"
#include "../../../includes/Server.hpp"

std::string  getPrefix(Client &client, Channel &channel)
{
    std::string prefix;
    // if (channel.isFounder(client.getNickname()))
    //     prefix = "~";
    if (channel.isOperator(client.getNickname()))
        prefix = "@";
    else // halfops are not implemented here
        prefix = ""; 
    return prefix;
}

bool    checkChanMask(std::string const& chanName)
{
    return (!chanName.empty() && chanName[0] == '#' && chanName.size() <= 50
        && (chanName.find_first_of("\r\n\b:, ") == std::string::npos)); // need to implement &channelName as well as #channelName ?
}