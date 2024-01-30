#include "Harl.hpp"

int	main(int argv, char **argc)
{
	Harl	theultimateHarl;

	if (argv != 2)
		return 0;
	else
		theultimateHarl.complain(argc[1]);
/* 	theultimateHarl.complain("DEBUG");
	std::cout << std::endl;
	theultimateHarl.complain("INFO");
	std::cout << std::endl;
	theultimateHarl.complain("WARNING");
	std::cout << std::endl;
	theultimateHarl.complain("ERROR");
	std::cout << std::endl;
	theultimateHarl.complain("HELLO"); */
	return 0;
}