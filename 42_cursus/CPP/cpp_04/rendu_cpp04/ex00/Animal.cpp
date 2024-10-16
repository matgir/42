#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout <<"Default Animal constructor called" << std::endl;
	_type = "default_animal";
	return;
}

Animal::Animal(Animal const & copy)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	this->_type = copy.getType();
	return;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return;
}

Animal	&Animal::operator=(Animal const & assign)
{
	std::cout << "Animal assignment operator called" << std::endl;

	if (this != &assign)
		this->_type = assign.getType();

	return *this;
}

std::string	Animal::getType(void)const
{
	return this->_type;
}

void	Animal::makeSound(void)const
{
	std::cout << "* ANIMAL SOUND *" << std::endl;
	return;
}
