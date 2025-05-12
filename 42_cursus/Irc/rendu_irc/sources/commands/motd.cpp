/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motd.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:23:46 by Helene            #+#    #+#             */
/*   Updated: 2024/12/18 13:22:38 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/irc.hpp"
#include "../../includes/commands.hpp"
#include "../../includes/Client.hpp"
#include "../../includes/Server.hpp"

void    Server::sendMotd(Client &client)
{
    std::ifstream motdFile;
    std::string line;

    motdFile.open("motd.txt");
    if (!motdFile.is_open())
    {
        client.addToWriteBuffer(ERR_NOMOTD(client.getNickname()));
        return ;
    }

    client.addToWriteBuffer(RPL_MOTDSTART(client.getNickname(), std::string(SERVER_NAME)));
    while (std::getline(motdFile, line)) // By default, the delimiter is \n (newline).
        client.addToWriteBuffer(RPL_MOTD(client.getNickname(), line));
    client.addToWriteBuffer(RPL_ENFODMOTD(client.getNickname()));
    
    motdFile.close();
}

void    cmdMotd(CommandContext &ctx)
{
    ctx._server.sendMotd(ctx._client);
}