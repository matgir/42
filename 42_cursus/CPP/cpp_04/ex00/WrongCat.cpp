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
	*this = copy;
	return;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	return;
}

WrongCat	&WrongCat::operator=(WrongCat const & copy)
{
	std::cout << "WrongCat assignment operator called" << std::endl;

	if (this != &copy)
		this->_type = copy.getType();

	return *this;
}

void	WrongCat::makeSound(void)const
{
	std::cout << "*WRONG MEOW*" << std::endl;
	return;
}
