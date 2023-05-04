#include <iostream>
#include "sample1_class.hpp"
#include "sample2_class.hpp"

int	main(void)
{
	Sample1	instance1('a', 42, 4.2f);
	Sample2	instance2('z', 13, 3.14f);

	instance1.a1++;
	instance1.a2++;
	instance1.a3++;
	instance2.a1++;
	instance2.a2++;
	instance2.a3++;
	std::cout << "instance1.a1 = " << instance1.a1 << std::endl;
	std::cout << "instance1.a1 = " << instance1.a2 << std::endl;
	std::cout << "instance1.a1 = " << instance1.a3 << std::endl;
	std::cout << "instance1.a1 = " << instance2.a1 << std::endl;
	std::cout << "instance1.a1 = " << instance2.a2 << std::endl;
	std::cout << "instance1.a1 = " << instance2.a3 << std::endl;

	return (0);
}