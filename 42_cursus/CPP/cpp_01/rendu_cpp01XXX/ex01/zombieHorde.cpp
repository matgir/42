#include "Zombie.h"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N < 0)
	{
		std::cout << "The Horde cannot have a negative number of Zombies" << std::endl;
		exit(1);
	}
	Zombie*	thehorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
			thehorde[i].setname(name);
	}
	return thehorde;
}