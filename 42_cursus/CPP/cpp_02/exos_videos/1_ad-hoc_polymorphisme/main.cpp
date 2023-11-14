#include "SampleClass.hpp"
#include <iostream>

int	main(void)
{
	Sample	test;

	test.bar('b');
	test.bar(9512);
	test.bar(1.89f);
	test.bar(test);

	return (1);
}