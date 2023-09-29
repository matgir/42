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
	std::cout << "Last name			: " << this->last_name << std::endl;
	std::cout << "Nickname			: " << this->nickname << std::endl;
	std::cout << "Phone number		: " << this->phone_number << std::endl;
	std::cout << "Darkest secret	: " << this->darkst_secret << std::endl;
	return;
}

/* in the set* function, pay attention if there is a new line when retrun (0)/false */

int	Contact::set_fname()
{
	std::string	fname;
	
	std::cout << "First name		: ";
	std::getline(std::cin, fname);
	if (fname.empty())
		return (0);
	for (int i = 0; fname[i]; i++)
		if (!std::isalpha(fname[i]) && fname[i] != '-' && fname[i] != ' ')
			return (0);
	this->first_name = fname;
	return (1);
}

bool	Contact::set_lname()
{
	std::string	lname;

	std::cout << "Last name			: ";
	std::getline(std::cin, lname);
	if (lname.empty())
		return false;
	for (int i = 0; lname[i]; i++)
		if (!std::isalpha(lname[i]) && lname[i] != '-' && lname[i] != ' ')
			return false;
	this->last_name = lname;
	return true;
}

int	Contact::set_nickname()
{
	std::string	nkname;

	std::cout << "Nickname			: ";
	std::getline(std::cin, nkname);
	if (nkname.empty())
		return (0);
	this->nickname = nkname;
	return (1);
}

int	Contact::set_phnumber()
{
	std::string	phnumber;

	std::cout << "Phone number		: ";
	std::getline(std::cin, phnumber);
	if (phnumber.empty())
		return (0);
	for (int i = 0; phnumber[i]; i++)
		if (!std::isdigit(phnumber[i]))
			return (0);
	this->phone_number = phnumber;
	return (1);
}

int	Contact::set_dkst_secret()
{
	std::string dkst;

	std::cout << "Darkest secret	: ";
	std::getline(std::cin, dkst);
	if (dkst.empty())
		return (0);
	this->darkst_secret = dkst;
	return (1);
}