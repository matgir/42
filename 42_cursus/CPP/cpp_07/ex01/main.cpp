#include "iter.hpp"

int	main(void)
{
	std::string	array[10];

	for (int i = 0; i < 10; i++)
		array[i] = 'b' + i;
	iter(array, 10, &showMe);
	return 0;
}