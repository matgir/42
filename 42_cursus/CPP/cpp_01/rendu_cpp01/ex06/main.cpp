#include "Harl.hpp"

int	main(int argv, char **argc)
{
	Harl	theultimateHarl;

	if (argv != 2)
		return 0;
	else
		theultimateHarl.complain(argc[1]);
	return 0;
}