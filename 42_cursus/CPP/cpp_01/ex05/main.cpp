#include "Harl.hpp"

int	main(void)
{
	Harl	theultimateHarl;

	theultimateHarl.complain("DEBUG");
	std::cout << std::endl;
	theultimateHarl.complain("INFO");
	std::cout << std::endl;
	theultimateHarl.complain("WARNING");
	std::cout << std::endl;
	theultimateHarl.complain("ERROR");
	std::cout << std::endl;
	theultimateHarl.complain("HELLO");
	return 0;
}