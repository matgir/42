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

int	Phonebook::setcontact()
{
	Contact		contact;
	// std::string	first_name;
	// std::string	last_name;
	// std::string	nickname;
	// std::string	phone_number;
	// std::string	darkst_secret;

	std::cout << "Please fill informations for new contact" << std::endl;
	std::cout << "First name : ";
	std::cin >> contact.first_name;
}