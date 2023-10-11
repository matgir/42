#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	return;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is no longer with us.";
	return;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}