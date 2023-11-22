
#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout <<"Default Dog constructor called" << std::endl;
	this->_type = "Dog";
	return;
}

Dog::Dog(Dog const & copy) : Animal(copy)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = copy;
	return;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	return;
}

Dog	&Dog::operator=(Dog const & copy)
{
	std::cout << "Dog assignment operator called" << std::endl;

	if (this != &copy)
		this->_type = copy.getType();

	return *this;
}

void	Dog::makeSound(void)const
{
	std::cout << "*BARK*" << std::endl;
	return;
}
