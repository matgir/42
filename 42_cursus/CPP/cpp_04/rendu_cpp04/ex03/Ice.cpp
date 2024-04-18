#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "Ice default constructor called" << std::endl;
	this->_type = "ice";
	return;
}

Ice::Ice(Ice const & copy) : AMateria(copy)
{
	// std::cout << "Ice copy constructor called" << std::endl;
	// this->_type = copy.getType(); // pas sur si oui ou non
	(void)copy;
	return;
}

Ice::~Ice(void)
{
	// std::cout << "Ice destructor called" << std::endl;
	return;
}

Ice	&Ice::operator=(Ice const & assign)
{
	// std::cout << "Ice assignment operator called" << std::endl;
	(void)assign;
	return *this;
}

void		Ice::use(ICharacter & target)
{
	/*	#### something that truly hurt de Icharacter, maybe the use of function
		getHurt()  in ICharacter */
	std::cout << "'* shoots an ice bolt at " << target.getName() << " *'"; // change for Cure
	std::cout << std::endl;
}

// Ice		*Ice::clone()const
AMateria	*Ice::clone()const
{
	Ice	*newice = new Ice();
	return newice;
}