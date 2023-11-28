#include "Zombie.hpp"

Zombie::Zombie() : _name("")
{
	return;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is no longer with us." << std::endl;
	return;
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

void	Zombie::setname(std::string name)
{
	this->_name = name;
	return;
}
