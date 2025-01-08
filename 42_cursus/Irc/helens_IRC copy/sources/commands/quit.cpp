/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:36:02 by Helene            #+#    #+#             */
/*   Updated: 2024/12/18 13:28:15 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/irc.hpp"
#include "../../includes/commands.hpp"
#include "../../includes/Client.hpp"
#include "../../includes/Server.hpp"

/*
When connections are terminated by a client-sent QUIT command, 
servers SHOULD prepend <reason> with the ASCII string "Quit: " when sending QUIT messages 
to other clients, to represent that this user terminated the connection themselves. 
This applies even if <reason> is empty, in which case the reason sent to other clients 
SHOULD be just this "Quit: " string.



Quand un client envoie la commande QUIT : serveur répond a ce client avce un ERROR msg, et ferme la connection.
Puis, il envoie un QUIT msg aux clients qui partagaient un/des channel(s) avec le client ayant envoyé le QUIT

SI une connection client est fermée sans que ce client ait envoyé un QUIT (CTRL+C par ex), 
le serveur distribue un QUIT msg aux autres clients (tous, ou seulement ceux avec des channels en commun ?),
du meme format qu'un QUIT msg normal, mais en renseignant <reason> avec la raison pour laquelle
la connection client a été rompue. 
*/
void    cmdQuit(CommandContext &ctx)
{
    std::string reason = ctx._parameters.empty() ? DEPARTURE_REASON : ctx._parameters[0];
    std::stringstream ss;
    ss << "Client " << ctx._client.getSockFd() << " disconnected.";
    ctx._server._log(INFO, ss.str());
    ctx._server.DisconnectClient(&ctx._client, reason); 
    
    // signifie (entre autres) a irssi de deconnecter le client qui a emit la cmd quit
    ctx._client.addToWriteBuffer(QUIT_RPL(ctx._client.getUserID(), reason));
}