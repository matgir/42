#include <iostream>
#include "sample_class.hpp"

int	main(void)
{
	Sample	instance;

	instance.foo++;
	std::cout << "instance.foo = " << instance.foo << std::endl;

	std::cout << "Choose de value of instance.foo : ";
	std::cin >> instance.foo;
	std::cout << "The new value of instance.foo = " << instance.foo << std::endl;

	return 0;
}