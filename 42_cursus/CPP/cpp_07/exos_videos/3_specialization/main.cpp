#include <iostream>
#include "Pair_class.hpp"

int	main(void)
{
	Pair< int, int >			p1(4, 2);
	Pair< std::string, float >	p2(std::string("Pi"), 3.14f);
	Pair< float, bool >			p3(4.2f, false);
	Pair< bool, bool >			p4(false, true);

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	std::cout << p4 << std::endl;

	return 0;
}