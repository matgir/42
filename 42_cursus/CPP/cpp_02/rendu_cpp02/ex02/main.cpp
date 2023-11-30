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

// int	main(void)
// {
// 	Fixed		a;
// 	Fixed		b(Fixed() + Fixed(2));
// 	Fixed		c(5.5f);
// 	Fixed		d(8.9f);
// 	Fixed		e(10);
// 	Fixed const	f(a);
// 	Fixed const	g(-12);
// 	Fixed		h(3);

// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;
// 	a = b;
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;

// 	if (d < e)
// 		std::cout << d <<" is smaller than " << e << std::endl;
// 	if (d > c)
// 		std::cout << d <<" is bigger than " << c << std::endl;
// 	if (d <= e)
// 		std::cout << d <<" is smaller or equal to " << e << std::endl;
// 	if (d >= c)
// 		std::cout << d << " is greater or equal to " << c << std::endl;
// 	if (a == b)
// 		std::cout << a << " is strictly equal to " << b << std::endl;
// 	if (c != b)
// 		std::cout << c << " is different to " << b << std::endl;

// 	std::cout << "add " << a << " and " << b << " to get " << a + b << std::endl;
// 	std::cout << "substract " << d << " by " << b << " to get " << d - b << std::endl;
// 	std::cout << "multiply " << d << " by " << b << " to get " << d * b << std::endl;
// 	std::cout << "multiply " << e << " by " << b << " to get " << e * b << std::endl;
// 	std::cout << "multiply " << d << " by " << c << " to get " << d * c << std::endl;
// 	std::cout << "divide " << e << " by " << h << " to get " << e / h << std::endl;
// 	std::cout << "divide " << c << " by " << b << " to get " << c / b << std::endl;
// 	std::cout << "divide " << d << " by " << c << " to get " << d / c << std::endl;
// 	// std::cout << "divide " << d << " by " << 0 << " to get " << d / 0 << std::endl;

// 	std::cout << a << "\n" << ++a << "\n" << a++ << "\n" << a << std::endl;
// 	std::cout << a << "\n" << --a << "\n" << a-- << "\n" << a << std::endl;

// 	std::cout << "the smaller between " << f << " and " << g << " is " << a.min(f, g) << std::endl;
// 	std::cout << "the smaller between " << d << " and " << c << " is " << a.min(d, c) << std::endl;
// 	std::cout << "the biggest between " << f << " and " << g << " is " << a.max(f, g) << std::endl;
// 	std::cout << "the biggest between " << d << " and " << c << " is " << a.max(d, c) << std::endl;

// 	return 0;
// }
