#include "IntegerClass.hpp"

int	main(void)
{
	IntegerClass x(30);
	IntegerClass y(10);
	IntegerClass z(0);

	std::cout << "Value of x = " << x << std::endl;
	std::cout << "Value of y = " << y << std::endl;
	y = IntegerClass(12);
	std::cout << "Value of y = " << y << std::endl;

	std::cout << "Value of z = " << z << std::endl;
	z = x + y;
	std::cout << "value of z = " << z << std::endl;

	return 0;
}