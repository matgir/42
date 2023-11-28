#include "Zombie.h"

void	randomChump(std::string name)
{
	Zombie	randomChump(name);
	randomChump.announce();
}