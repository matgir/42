#include "AMateria.hpp"

AMateria::AMateria(void)
{
	// std::cout << "AMateria default constructor called" << std::endl;
	this->_type = "Default type";
	return;
}

AMateria::AMateria(std::string const & type)
{
	// std::cout << "AMateria typing constructor called" << std::endl;
	this->_type = type;
	return;
}

AMateria::AMateria(AMateria const & copy)
{
	// std::cout << "AMateria copy constructor called" << std::endl;
	this->_type = copy.getType();
	return;
}

AMateria::~AMateria(void)
{
	// std::cout << "AMateria destructor called" << std::endl;
	return;
}

AMateria	&AMateria::operator=(AMateria const & assign)
{
	// std::cout << "AMateria assignment operator called" << std::endl;

	if (this != &assign)
		this->_type = assign.getType();

	return *this;
}

std::string	const & AMateria::getType()const
{
	return this->_type;
}

void		AMateria::use(ICharacter & target)
{
	std::cout << "I'm never going to be used , because AMateria can't be instanciated !";
	std::cout << std::endl;
	(void) target;
}
