#include "Zombie.h"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	thehorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
			thehorde[i].setname(name);
	}
	return thehorde;
}