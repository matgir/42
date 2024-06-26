/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:09 by mgirardo          #+#    #+#             */
/*   Updated: 2023/10/03 16:05:14 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookClass.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT) : ";
		if (!std::getline(std::cin, command))
			break;
		else if (command == "ADD")
			phonebook.setcontact();
		else if (command == "SEARCH")
			phonebook.displaycontacts();
		else if (command == "EXIT")
			break;
		else
		{
			if(!std::cin.good())
				exit(1);
			std::cout << "Not a valid command." << std::endl;
		}
	}
	return 0;
}
