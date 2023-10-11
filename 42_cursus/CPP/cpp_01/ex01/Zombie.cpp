#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "";
	return;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is no longer with us." << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

void	Zombie::setname(std::string name)
{
	this->_name = name;
	return;
}