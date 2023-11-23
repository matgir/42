#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout <<"Default Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_catBrain = new Brain();
	return;
}

Cat::Cat(Cat const & copy) : Animal(copy)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	this->_type = copy.getType();
	this->_catBrain = new Brain(*(copy.getBrain()));
	return;
}

Cat::~Cat(void)
{
	delete this->_catBrain;
	std::cout << "Cat destructor called" << std::endl;
	return;
}

Cat	&Cat::operator=(Cat const & assign)
{
	std::cout << "Cat assignment operator called" << std::endl;

	if (this != &assign)
	{
		this->_type = assign.getType();
		this->_catBrain = new Brain(*(assign.getBrain()));
	}

	return *this;
}

void	Cat::makeSound(void)
{
	std::cout << "*MEOW*" << std::endl;
	return;
}

Brain	*Cat::getBrain(void)const
{
	return this->_catBrain;
}