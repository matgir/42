#include "Water.hpp"

Water::Water(void) : AMateria("water")
{
	// std::cout << "Water default constructor called" << std::endl;
	this->_type = "water";
	return;
}

Water::Water(Water const & copy) : AMateria(copy)
{
	// std::cout << "Water copy constructor called" << std::endl;
	// this->_type = copy.getType(); // pas sur si oui ou non
	(void)copy;
	return;
}

Water::~Water(void)
{
	// std::cout << "Water destructor called" << std::endl;
	return;
}

Water	&Water::operator=(Water const & assign)
{
	// std::cout << "Water assignment operator called" << std::endl;
	(void)assign;
	return *this;
}

void		Water::use(ICharacter & target)
{
	/*	#### something that truly hurt de Icharacter, maybe the use of function
		getHurt()  in ICharacter */
	std::cout << "'* shoots a stream of water at " << target.getName() << " *'"; // change for Water
	std::cout << std::endl;
}

// Water			*Water::clone()const
AMateria		*Water::clone()const
{
	Water	*newWater = new Water();
	return newWater;
}