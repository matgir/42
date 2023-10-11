#include "zombie.h"

int	main(void)
{
	Zombie	henri = Zombie("Henri");
	henri.announce();

	Zombie*	bazil = newZombie("Bazil");
	bazil->announce();
	delete bazil;

	randomChump("Franklin");

	return;
}