/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:24:09 by Helene            #+#    #+#             */
/*   Updated: 2024/12/18 13:44:26 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"
#include "../includes/Client.hpp" 

#define    INVALID_ARGUMENTS    1

bool serverShutdown = false;

void handleSignal(int signal)
{
    (void) signal;
    serverShutdown = true;
}

/* struct sigaction : used to define the behavior of our IRC when a specific signal
    is received
    act.sa_handler can hold any given function, here the handleSignal function
    will set our serverShutdown to true to shutdown the IRC server
bzero is used to ensure no unexpected behavior due to uninitialized fields
sigaction() installs the sa_handler for the SIGINT/SIGQUIT signal, ctrl+C/ctrl+'\'
 */

void setSignalHandlers()
{
    struct sigaction act;
    
    bzero(&act, sizeof(act));
    act.sa_handler = handleSignal;
    
    sigaction(SIGINT, &act, NULL);
    sigaction(SIGQUIT, &act, NULL);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Wrong number of arguments : 2 required, " << argc - 1 << "given." << std::endl;
        std::cerr << "Input should look like this : ./ircserv <port> <password>" << std::endl;
        return (INVALID_ARGUMENTS); 
    }
    long l = atol(argv[1]);
    if (l < 1024 || l > 65535)
    {
        std::cerr << "Invalid port number" << std::endl;
        return (INVALID_ARGUMENTS);
    }
    

    setSignalHandlers();
    Server IrcServer(argv[1], argv[2]);
        
    try {
        IrcServer.InitServer();
        IrcServer.RunServer();
    }
    catch (std::exception const& e) {
        std::cout << "Error : " << e.what() << std::endl;
    }
    
    IrcServer.ShutdownServer();
}