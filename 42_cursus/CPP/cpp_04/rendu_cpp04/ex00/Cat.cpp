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
	this->_type = copy.getType();
	return;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	return;
}

Cat	&Cat::operator=(Cat const & assign)
{
	std::cout << "Cat assignment operator called" << std::endl;

	if (this != &assign)
		this->_type = assign.getType();

	return *this;
}

void	Cat::makeSound(void)const
{
	std::cout << "* MEOW *" << std::endl;
	return;
}
