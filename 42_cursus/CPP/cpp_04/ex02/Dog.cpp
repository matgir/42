#include "Dog.hpp"

Dog::Dog(void) : AAnimal()
{
	std::cout <<"Default Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	return;
}

Dog::Dog(Dog const & copy) : AAnimal(copy)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	this->_type = copy.getType();
	this->_brain = new Brain(*(copy.getBrain()));
	return;
}

Dog::~Dog(void)
{
	if (this->_brain)
		delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
	return;
}

Dog	&Dog::operator=(Dog const & assign)
{
	std::cout << "Dog assignment operator called" << std::endl;

	if (this != &assign)
	{
		this->_type = assign.getType();
		delete this->getBrain();
		this->_brain = new Brain(*(assign.getBrain()));
	}

	return *this;
}

void	Dog::makeSound(void)
{
	std::cout << "* BARK *" << std::endl;
	return;
}

Brain	*Dog::getBrain(void)const
{
	return this->_brain;
}