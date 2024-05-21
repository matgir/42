#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout <<"Default WrongAnimal constructor called" << std::endl;
	_type = "WrongAnimal";
	return;
}

WrongAnimal::WrongAnimal(WrongAnimal const & copy)
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	this->_type = copy.getType();
	return;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const & assign)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;

	if (this != &assign)
		this->_type = assign.getType();

	return *this;
}

std::string	WrongAnimal::getType(void)const
{
	return this->_type;
}

void	WrongAnimal::makeSound(void)const
{
	std::cout << "*Wrong Animal sound*" << std::endl;
	return;
}
