#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	//0
	std::cout << ++a << std::endl;
	//0.00390625
	std::cout << a << std::endl;
	//0.00390625
	std::cout << a++ << std::endl;
	//0.00390625
	std::cout << a << std::endl;
	//0.0078125
	std::cout << b << std::endl;
	//10.1016

	std::cout << Fixed::max( a, b ) << std::endl;
	//10.1016

	return 0;
}

