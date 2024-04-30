#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	std::cout << std::endl << std::endl;
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
	}
	std::cout << std::endl << std::endl;
	{
		Data *		data1 = new Data;

		data1->dataChar = 'g';
		data1->dataName = "Marvin";
		data1->dataNumber = 42;

		/*----- Output data -----*/
		std::cout << data1 << std::endl;
		std::cout << data1->dataChar << std::endl;
		std::cout << data1->dataName << std::endl;
		std::cout << data1->dataNumber << std::endl;
		std::cout << std::endl;

		/*----- Output deserialized value -----*/
		std::cout << Serializer::deserialize(Serializer::serialize(data1)) << std::endl;
		std::cout << (Serializer::deserialize(Serializer::serialize(data1)))->dataChar << std::endl;
		std::cout << (Serializer::deserialize(Serializer::serialize(data1)))->dataName << std::endl;
		std::cout << (Serializer::deserialize(Serializer::serialize(data1)))->dataNumber << std::endl;
		std::cout << std::endl;

		delete data1;
	}
	std::cout << std::endl << std::endl;
	return 0;

}
