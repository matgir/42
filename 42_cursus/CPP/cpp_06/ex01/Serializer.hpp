#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

struct Data;

class Serializer
{
	private:

		Serializer(void);
		Serializer(Serializer const & copy);
		virtual ~Serializer(void);

		Serializer	&operator=(Serializer const & assign);

	public:

		static uintptr_t	serialize(Data * ptr);
		static Data *		deserialize(uintptr_t raw);
};

#endif
