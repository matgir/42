/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:36:02 by Helene            #+#    #+#             */
/*   Updated: 2024/10/04 17:15:37 by hlesny           ###   ########.fr       */
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
    std::string reason = ctx._parameters.empty() ? "" : ctx._parameters[0];
    // ctx._client.addToWriteBuffer("QUIT :" + reason + CRLF);
    
    // The server acknowledges this by replying with an ERROR message and closing the connection to the client.
    ctx._client.addToWriteBuffer(ERROR_RPL(reason));
    
    std::stringstream ss;
    ss << ctx._client.getSockFd();
    ctx._server._log(INFO, "Client " + ss.str() + " disconnected.");
    ctx._server.DisconnectClient(&ctx._client, reason);

    
    // envoie un QUIT msg aux autres clients mtn ou apres ?
    /*
        -> Dans la classe Channel :
            -   créer une methode pour envoyer un msg a tous les clients de ce channel 
                (sauf au client étant a l'origine de ce msg)
        -> Dans la classe Serveur :
            -   getChannel(std::string channelName) permettant de recup un channel a partir du nom
            
    =>  pour envoyer un msg a tous les clients ayant des channels en commun avec le client déconnecté,
        peut 1) parser la liste des channels dans lesquelles est ce client, appeler getChannel() pour 
                chacun des channels, et pour chaque channel appeler la méthode Channel::distributeToAll(Client &client),
                qui distribue un msg a tous les clients du channel sauf celui spécifié en paramètre (car est la source du msg)
             2) parser la liste des channels existants dans le serveur, checker pour chaque channel si le client est dedans
                (nécessite la méthode bool Channel::isIn(std::string const& client, ou Client const& client)),
                puis distributeToAll() si ce client est dans le channel
        
        DANS TOUS LES CAS : ne peut pas direct envoyer le msg. ajouter chaque recipient a une liste,
            puis envoyer un msg a tous les recipients de cette liste quand a fini de parser tous les channels
            dans lesquels était le client disconnected. sinon risque d'envoyer des doublons (si le client
            déconnecté a plus d'un channel en commun avec un autre client par ex)
                
    */
    
    
}