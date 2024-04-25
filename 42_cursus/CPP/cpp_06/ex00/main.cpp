#include "AScalarConverter.hpp"

int	main(int ac, char **av)
{
	std::cout << "Minimum value for float: " << FLT_MIN << std::endl;
	std::cout << "Maximum value for float: " << FLT_MAX << std::endl;
	if (ac != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return 1;
	}
	else
		AScalarConverter::convert(av[1]);
	return 0;
/* 	(void)ac;
	(void)av;
	AScalarConverter::convert(INFINITY);
 */	return 0;
}
