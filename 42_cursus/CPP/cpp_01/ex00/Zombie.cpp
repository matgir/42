#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "Bernard";
	return;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is no longer with us.";
	return;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}