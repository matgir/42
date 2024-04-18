#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point	a(3.0f, -1.0f);
	Point	b(-1.0f, 3.0f);
	Point	c(4.0f, 2.0f);
	Point	d(2.0f, 0);
	Point	e(0.0f, 2.7f);
	Point	f(2.0f, 4.0f);
	Point	g(2.0f, 2.0f);

	if (bsp(a, b, c, d))
		std::cout << "Point d is in the triangle\n";
	else
		std::cout << "Point d is not in the triangle\n";
	if (bsp(a, b, c, e))
		std::cout << "Point e is in the triangle\n";
	else
		std::cout << "Point e is not in the triangle\n";
	if (bsp(a, b, c, f))
		std::cout << "Point f is in the triangle\n";
	else
		std::cout << "Point f is not in the triangle\n";
	if (bsp(a, b, c, g))
		std::cout << "Point g is in the triangle\n";
	else
		std::cout << "Point g is not in the triangle\n";

	return 0;
}
