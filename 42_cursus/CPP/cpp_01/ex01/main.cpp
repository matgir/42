#include "Zombie.h"

int	main(int ac, char **av)
{
	if (ac != 4 || strlen(av[1]) > 10 || strlen(av[3]) > 10)
	{
		std::cout << "Please start program like this\nMyZombieHorde <number_of_zombies> <zombie_name> <zombie index>" << std::endl;
		return (1);
	}
	for (int i = 0; av[1][i]; i++)
	{
		if (!std::isdigit(av[1][i]))
	{
		std::cout << "Please choose a valid number of Zombies" << std::endl;
		return (1);
	}
	}
	for (int i = 0; av[3][i]; i++)
	{
		if (!std::isdigit(av[3][i]))
		{
		std::cout << "Please choose a valid index" << std::endl;
		return (1);
		}
	}
	if (!strtol(av[1], 0, 10) || !strtol(av[3], 0, 10))
			{
		std::cout << "out of int range" << std::endl;
		return (1);
		}
	long int	j = strtol(av[1], 0, 10);
	long int	i = strtol(av[3], 0, 10);
	if (i > ac || i < 0)
	{
		std::cout << "Please choose a valid index" << std::endl;
		return (1);
	}
	Zombie* thehorde = zombieHorde(j , av[2]);
	thehorde[i].announce();
	Zombie::getnbinst();
	delete [] thehorde;

	return (1);
}