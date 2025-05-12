/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandContext.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:48:43 by Helene            #+#    #+#             */
/*   Updated: 2024/12/18 12:54:46 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "irc.hpp"

class Server;
class Client; 

class   CommandContext
{
    public :
        std::string                 _prefix;
        std::string                 _command;
        std::vector<std::string>    _parameters;
        Client&                     _client;
        Server&                     _server;
    
    public :
        CommandContext(Client &client);
        CommandContext(std::string const& prefix, std::string const& cmd, std::vector<std::string> const& parameters, Client &client);
        ~CommandContext() {}
        void                            fillCommand(std::string const& prefix, std::string const& cmd, std::vector<std::string> const& parameters);
        void                            setCommand(std::string const& name);
        std::string                     getCommand(void) const;
};
