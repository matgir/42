// replace canonical by your class name
// replace getvariable(void)const par nouveau getteur
// replace variable by your variable name

#ifndef ASERIALIZER_HPP
# define ASERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

class Data;

class ASerializer
{
	public:

		virtual ~ASerializer(void) = 0;

		static uintptr_t	serialize(Data * ptr);
		static Data *		deserialise(uintptr_t raw);

		operator unsigned int()	{return }
};

#endif

#include "ASerializer.hpp"

ASerializer::~ASerializer(void)
{
	std::cout << "ASerializer destructor called" << std::endl;
	return;
}

uintptr_t	ASerializer::serialize(Data * ptr)
{
	/* ################## */
}

Data *		ASerializer::deserialize(uintptr_t raw)
{
	/* #################### */
}
