/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandsHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:18:29 by Helene            #+#    #+#             */
/*   Updated: 2024/09/27 15:50:40 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "irc.hpp"
#include "commands.hpp"

/* redefinition d'un pointeur sur fonction prenant en parametre une CommandContext et retournant void
->  permet de stocker dans un container toutes les fonctions correspondant aux commandes gérées, 
    il faut cependant s'assurer que chaque fonction de commande prenne uniquement un CommandContext en argument,
    vérifier donc que CommandContext donne bien accès à toutes les infos nécessaires au traitement de la commande
*/
typedef void (*CommandExecutor)(CommandContext &ctx); // reference to CommandContext bc will be modifying the client and server attributes

// classe repertoriant avec le container map toutes les commandes implémentées
// a besoin de quoi comme attributs a part la map ?
class   CommandsHandler
{
    public :
        typedef std::map<std::string, CommandExecutor> commandsMap;
        typedef commandsMap::iterator commandsMapIt;
    
    public : 
        commandsMap    _commands; // a moyen de la mettre en private ?

    public :
        CommandsHandler();
        ~CommandsHandler() {}
        void                    execCommand(std::string const& name);
};
