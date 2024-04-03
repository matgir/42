#ifndef DATA_HPP
# define DATA_HPP

# include "Serializer.hpp"

class Serializer;

typedef struct	Data
{
	std::string	dataName;
	int			dataNumber;
	char		dataChar;
}				Data;

#endif