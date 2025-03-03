/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:24:51 by Helene            #+#    #+#             */
/*   Updated: 2024/12/18 13:13:11 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/irc.hpp"
#include "../../../includes/commands.hpp"
#include "../../../includes/Client.hpp"
#include "../../../includes/Server.hpp"

std::string  getPrefix(Client &client, Channel &channel)
{
    std::string prefix;
    if (channel.isOperator(client.getNickname()))
        prefix = "@";
    else // halfops are not implemented here
        prefix = ""; 
    return prefix;
}

bool    checkChanMask(std::string const& chanName)
{
    return (!chanName.empty() && chanName[0] == '#' && chanName.size() <= 50
        && (chanName.find_first_of("\r\n\b:, ") == std::string::npos));
}