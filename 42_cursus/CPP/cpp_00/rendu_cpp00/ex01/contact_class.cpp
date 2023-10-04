/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:04:37 by mgirardo          #+#    #+#             */
/*   Updated: 2023/10/03 16:04:48 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook_class.hpp"

Contact::Contact(void)
{
	Contact::first_name = "";
	Contact::last_name = "";
	Contact::nickname = "";
	Contact::phone_number = "";
	Contact::darkst_secret = "";
	return;
}

Contact::~Contact(void)
{
	return;
}

void	Contact::displaycontact()
{
	std::cout << "First name		: " << this->first_name << std::endl;
	std::cout << "Last name		: " << this->last_name << std::endl;
	std::cout << "Nickname		: " << this->nickname << std::endl;
	std::cout << "Phone number		: " << this->phone_number << std::endl;
	std::cout << "Darkest secret		: " << this->darkst_secret << std::endl;
	return;
}

/*
   in set* functions, new line when retrun false, because the user press
   enter in order for the program to receive std::cin
   */

bool	Contact::set_fname()
{
	std::string	fname;

	std::cout << "First name		: ";
	std::getline(std::cin, fname);
	if (fname.empty())
		return false;
	for (int i = 0; fname[i]; i++)
		if (!std::isalpha(fname[i]) && fname[i] != '-' && fname[i] != ' ')
			return false;
	this->first_name = fname;
	return true;
}

bool	Contact::set_lname()
{
	std::string	lname;

	std::cout << "Last name		: ";
	std::getline(std::cin, lname);
	if (lname.empty())
		return false;
	for (int i = 0; lname[i]; i++)
		if (!std::isalpha(lname[i]) && lname[i] != '-' && lname[i] != ' ')
			return false;
	this->last_name = lname;
	return true;
}

bool	Contact::set_nickname()
{
	std::string	nkname;

	std::cout << "Nickname		: ";
	std::getline(std::cin, nkname);
	if (nkname.empty())
		return false;
	this->nickname = nkname;
	return true;
}

bool	Contact::set_phnumber()
{
	std::string	phnumber;

	std::cout << "Phone number		: ";
	std::getline(std::cin, phnumber);
	if (phnumber.empty())
		return false;
	for (int i = 0; phnumber[i]; i++)
		if (!std::isdigit(phnumber[i]))
			return false;
	this->phone_number = phnumber;
	return true;
}

bool	Contact::set_dkst_secret()
{
	std::string dkst;

	std::cout << "Darkest secret		: ";
	std::getline(std::cin, dkst);
	if (dkst.empty())
		return false;
	this->darkst_secret = dkst;
	return true;
}

std::string	Contact::short_name(int i)
{
	std::string	toresize;

	if (i == 1)
		toresize = this->first_name;
	else if (i == 2)
		toresize = this->last_name;
	else if (i == 3)
		toresize = this->nickname;
	if (toresize.size() <= 10)
		toresize.resize(10, ' ');
	else
	{
		toresize.resize(10);
		toresize[9] = '.';
	}
	return (toresize);
}