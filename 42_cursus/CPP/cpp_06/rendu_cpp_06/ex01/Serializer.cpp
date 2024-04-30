#include "Serializer.hpp"

Serializer::Serializer(void)
{
	return;
}

Serializer::Serializer(Serializer const & copy)
{
	(void)copy;
	return;
}

Serializer::~Serializer(void)
{
	return;
}

Serializer	&Serializer::operator=(Serializer const & assign)
{
	(void)assign;
	return *this;
}

uintptr_t	Serializer::serialize(Data * ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
