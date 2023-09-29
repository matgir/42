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
}