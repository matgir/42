// replace canonical by your class name
// replace getvariable(void)const par nouveau getteur
// replace variable by your variable name

#ifndef ASCALARCONVERTER_HPP
# define ASCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <cmath>
# include <iomanip>
// # include <cfloat>

class AScalarConverter
{
	public:
		virtual		~AScalarConverter(void) = 0;
		static void	convert(std::string input);
};

#endif
