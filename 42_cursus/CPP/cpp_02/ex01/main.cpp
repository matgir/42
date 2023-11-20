#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
// Default constructor called
	Fixed	b(a);
// Copy constructor called
// Copy assignment operator called // <-- This line may be missing depending on your implementation
// getRawBits member function called
	Fixed	c;
// Default constructor called

	c = b;
// Copy assignment operator called
// getRawBits member function called

	std::cout << a.getRawBits() << std::endl;
// getRawBits member function called
// 0
	std::cout << b.getRawBits() << std::endl;
// getRawBits member function called
// 0
	std::cout << c.getRawBits() << std::endl;
// getRawBits member function called
// 0

	return 1;
// Destructor called
// Destructor called
// Destructor called
}
