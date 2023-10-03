/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:31 by mgirardo          #+#    #+#             */
/*   Updated: 2023/10/03 17:44:43 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook_class.hpp"

Phonebook::Phonebook(void)
{
	nbcontact = 0;
	return;
}

Phonebook::~Phonebook(void)
{
	return;
}

void	Phonebook::setcontact(Phonebook phonebook)
{
	Contact		contact;

	std::cout << "Please fill informations for new contact" << std::endl;
	while (!contact.set_fname())
		std::cout << "Please enter valid first name (letters, space or -)" << std::endl;
	while (!contact.set_lname())
		std::cout << "Please enter valid last name (letters, space or -)" << std::endl;
	while (!contact.set_nickname())
		std::cout << "Please enter a nickname" << std::endl;
	while (!contact.set_phnumber())
		std::cout << "Please enter a valid phone number (digit)" << std::endl;
	while (!contact.set_dkst_secret())
		std::cout << "Please enter a darkest secret" << std::endl;
	this->updatephonebook(contact);
	return;
}

void	Phonebook::updatephonebook(Contact newcontact)
{
	if (this->nbcontact == 8)
	{
		for (int i = 1; i <= 7; i++)
		{
			this->contacts[i - 1] = this->contacts[i];
		}
		this->nbcontact = 7;
	}
	this->contacts[nbcontact] = newcontact;
	this->nbcontact++;
	return;
}

/*	how to display contactS
	1         |albertine |dela-roch.|nickname  
	*/

void	Phonebook::displaycontacts()
{
	int	j;

	for (int i = 0; i < this->nbcontact; i++)
	{
		std::cout << i + 1 << "         |";
		std::cout << this->contacts[i].short_name(1) << "|";
		std::cout << this->contacts[i].short_name(2) << "|";
		std::cout << this->contacts[i].short_name(3) << std::endl;
	}
	while(1)
	{
		std::cout << "Choose contact index : ";
		std::cin >> j;
		if (j < 1 || j > this->nbcontact - 1)
			std::cout << "Wrong index" << std::endl;
		else
		{
			this->contacts[j - 1].displaycontact();
			break;
		}
	}
	return;
}
