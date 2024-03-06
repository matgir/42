// replace canonical by your class name
// replace getvariable(void)const par nouveau getteur
// replace variable by your variable name

#ifndef ASCALARCONVERTER_HPP
# define ASCALARCONVERTER_HPP

# include <iostream>

class AScalarConverter
{
	public:
		virtual		~AScalarConverter(void) = 0;
		static void	convert(void * info);
};

#endif

#include AScalarConverter.hpp

void	AScalarConverter::convert(void * info)
{
	
}