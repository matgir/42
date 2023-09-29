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

/* gerer quand nb contact superieur a 8 */

}