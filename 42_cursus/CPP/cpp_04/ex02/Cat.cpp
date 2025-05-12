#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	std::cout <<"Default Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	return;
}

Cat::Cat(Cat const & copy) : AAnimal(copy)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	this->_type = copy.getType();
	this->_brain = new Brain(*(copy.getBrain()));
	return;
}

Cat::~Cat(void)
{
	if (this->_brain)
		delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
	return;
}

Cat	&Cat::operator=(Cat const & assign)
{
	std::cout << "Cat assignment operator called" << std::endl;

	if (this != &assign)
	{
		this->_type = assign.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*(assign.getBrain()));
	}

	return *this;
}

void	Cat::makeSound(void)
{
	std::cout << "* MEOW *" << std::endl;
	return;
}

Brain	*Cat::getBrain(void)const
{
	return this->_brain;
}