#include "Zombie.h"

int	main(void)
{
	int	i = 42;
	Zombie* thehorde = zombieHorde(i , "Brendon");
	for (int j = 0; j < i; j++)
		thehorde[j].announce();
	// thehorde[-42].announce();
	// thehorde[42].announce();
	delete [] thehorde;

	return 0;
}