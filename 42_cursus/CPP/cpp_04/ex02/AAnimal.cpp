#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout <<"Default AAnimal constructor called" << std::endl;
	_type = "animal";
	return;
}

AAnimal::AAnimal(AAnimal const & copy)
{
	std::cout << "Copy AAnimal constructor called" << std::endl;
	this->_type = copy.getType();
	return;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
	return;
}

AAnimal	&AAnimal::operator=(AAnimal const & assign)
{
	std::cout << "AAnimal assignment operator called" << std::endl;

	if (this != &assign)
		this->_type = assign.getType();

	return *this;
}

std::string	AAnimal::getType(void)const
{
	return this->_type;
}
