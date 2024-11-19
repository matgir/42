/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motd.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:23:46 by Helene            #+#    #+#             */
/*   Updated: 2024/10/03 14:29:18 by Helene           ###   ########.fr       */
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

    // Va pas l'ouvrir à chaque commande MOTD, si ? Plutot le stocker dans le serveur 
    motdFile.open("motd.txt");
    if (!motdFile.is_open())
    {
        // Error : could not open Motd file (missing or bad access rights)
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
    // arguments checks etc
    // inutile car n'aura dans tous les cas qu'un seul serveur
    
    ctx._server.sendMotd(ctx._client);
}