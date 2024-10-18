#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int	main(void)
{
	std::cout << std::endl << std::endl;
	{
		std::list<int>	lst;

		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(-3658);
		lst.push_back(2147483647);
		lst.push_back(-12);
		lst.push_back(654);

		try
		{
			std::cout << *easyfind(lst, 2147483647) << std::endl;
			std::cout << *easyfind(lst, -3658) << std::endl;
			std::cout << *easyfind(lst, -3) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl << std::endl;
	{
		std::vector<int>	vect;

		vect.push_back(1);
		vect.push_back(2);
		vect.push_back(-3658);
		vect.push_back(2147483647);
		vect.push_back(-12);
		vect.push_back(654);

		try
		{
			std::cout << *easyfind(vect, 1) << std::endl;
			std::cout << *easyfind(vect, -12) << std::endl;
			std::cout << *easyfind(vect, 23) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl << std::endl;
	return 0;
}
