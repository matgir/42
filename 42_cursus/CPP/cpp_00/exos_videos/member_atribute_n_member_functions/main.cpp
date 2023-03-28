#include <iostream>
#include "sample_class.hpp"

int	main()
{
	Sample	instance;

	instance.foo = 42;
	std::cout << "instance.foo = " << instance.foo << std::endl;

	instance.bar();
	return 0;
}