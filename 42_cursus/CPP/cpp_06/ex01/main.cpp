#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	Data *		data1 = new Data;
	uintptr_t	raw;
	Data *		data2;

	data1->dataChar = 'g';
	data1->dataName = "Marvin";
	data1->dataNumber = 42;

	raw = Serializer::serialize(data1);
	data2 = Serializer::deserialize(raw);

	std::cout << data2->dataChar << std::endl;
	std::cout << data2->dataName << std::endl;
	std::cout << data2->dataNumber << std::endl;

	delete data1;

	return 0;
}