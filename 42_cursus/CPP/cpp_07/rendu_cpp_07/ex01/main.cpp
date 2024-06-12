#include "iter.hpp"

int	main(void)
{
	std::string	array[10];
	int			intArray[10];

	for (int i = 0; i < 10; i++)
{
		array[i] = 'b' + i;
		intArray[i] = i;
}
	std::cout << std::endl << std::endl;
	iter(array, 10, &showMe);
	std::cout << std::endl << std::endl;
	iter(array, 10, &incrementMe);
	iter(array, 10, &showMe);
	std::cout << std::endl << std::endl;
	iter(intArray, 10, &showMe);
	std::cout << std::endl << std::endl;
	iter(intArray, 10, &incrementMe);
	iter(intArray, 10, &showMe);
	std::cout << std::endl << std::endl;
	return 0;
}