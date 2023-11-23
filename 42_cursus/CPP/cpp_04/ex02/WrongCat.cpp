#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout <<"Default WrongCat constructor called" << std::endl;
	this->_type = "WrongCat";
	return;
}

WrongCat::WrongCat(WrongCat const & copy) : WrongAnimal(copy)
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
	this->_type = copy.getType();
	return;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	return;
}

WrongCat	&WrongCat::operator=(WrongCat const & assign)
{
	std::cout << "WrongCat assignment operator called" << std::endl;

	if (this != &assign)
		this->_type = assign.getType();

	return *this;
}

void	WrongCat::makeSound(void)
{
	std::cout << "*WRONG MEOW*" << std::endl;
	return;
}
