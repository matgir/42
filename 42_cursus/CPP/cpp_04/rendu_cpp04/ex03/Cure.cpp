#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Cure default constructor called" << std::endl;
	this->_type = "cure";
	return;
}

Cure::Cure(Cure const & copy) : AMateria(copy)
{
	// std::cout << "Cure copy constructor called" << std::endl;
	// this->_type = copy.getType(); // pas sur si oui ou non
	(void)copy;
	return;
}

Cure::~Cure(void)
{
	// std::cout << "Cure destructor called" << std::endl;
	return;
}

Cure	&Cure::operator=(Cure const & assign)
{
	// std::cout << "Cure assignment operator called" << std::endl;
	(void)assign;
	return *this;
}

void		Cure::use(ICharacter & target)
{
	/*	#### something that truly hurt de Icharacter, maybe the use of function
		getHurt()  in ICharacter */
	std::cout << "'* heals " << target.getName() << "'s wounds *'"; // change for Cure
	std::cout << std::endl;
}

// Cure			*Cure::clone()const
AMateria		*Cure::clone()const
{
	Cure	*newCure = new Cure();
	return newCure;
}