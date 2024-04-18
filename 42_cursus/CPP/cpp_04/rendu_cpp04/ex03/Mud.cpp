#include "Mud.hpp"

Mud::Mud(void) : AMateria("mud")
{
	// std::cout << "Mud default constructor called" << std::endl;
	this->_type = "mud";
	return;
}

Mud::Mud(Mud const & copy) : AMateria(copy)
{
	// std::cout << "Mud copy constructor called" << std::endl;
	// this->_type = copy.getType(); // pas sur si oui ou non
	(void)copy;
	return;
}

Mud::~Mud(void)
{
	// std::cout << "Mud destructor called" << std::endl;
	return;
}

Mud	&Mud::operator=(Mud const & assign)
{
	// std::cout << "Mud assignment operator called" << std::endl;
	(void)assign;
	return *this;
}

void		Mud::use(ICharacter & target)
{
	/*	#### something that truly hurt de Icharacter, maybe the use of function
		getHurt()  in ICharacter */
	std::cout << "'* shoots a pile of mud at " << target.getName() << " *'"; // change for Mud
	std::cout << std::endl;
}

// Mud			*Mud::clone()const
AMateria		*Mud::clone()const
{
	Mud	*newMud = new Mud();
	return newMud;
}