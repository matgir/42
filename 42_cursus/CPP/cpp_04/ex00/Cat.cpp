#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout <<"Default Cat constructor called" << std::endl;
	this->_type = "Cat";
	return;
}

Cat::Cat(Cat const & copy) : Animal(copy)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = copy;
	return;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	return;
}

Cat	&Cat::operator=(Cat const & copy)
{
	std::cout << "Cat assignment operator called" << std::endl;

	if (this != &copy)
		this->_type = copy.getType();

	return *this;
}

void	Cat::makeSound(void)const
{
	std::cout << "*MEOW*" << std::endl;
	return;
}
