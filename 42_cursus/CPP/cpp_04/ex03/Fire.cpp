#include "Fire.hpp"

Fire::Fire(void) : AMateria("fire")
{
	// std::cout << "Fire default constructor called" << std::endl;
	this->_type = "fire";
	return;
}

Fire::Fire(Fire const & copy) : AMateria(copy)
{
	// std::cout << "Fire copy constructor called" << std::endl;
	// this->_type = copy.getType(); // pas sur si oui ou non
	(void)copy;
	return;
}

Fire::~Fire(void)
{
	// std::cout << "Fire destructor called" << std::endl;
	return;
}

Fire	&Fire::operator=(Fire const & assign)
{
	// std::cout << "Fire assignment operator called" << std::endl;
	(void)assign;
	return *this;
}

void		Fire::use(ICharacter & target)
{
	/*	#### something that truly hurt de Icharacter, maybe the use of function
		getHurt()  in ICharacter */
	std::cout << "'* shoots a sphere of fire at " << target.getName() << " *'"; // change for Fire
	std::cout << std::endl;
}

// Fire			*Fire::clone()const
AMateria		*Fire::clone()const
{
	Fire	*newFire = new Fire();
	return newFire;
}