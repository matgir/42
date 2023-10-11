#include "Zombie.h"

int	main(void)
{
	Zombie* thehorde = zombieHorde(42, "Marvin");
	thehorde[6].announce();
	delete [] thehorde;

	return (1);
}