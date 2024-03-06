// replace canonical by your class name
// replace getvariable(void)const par nouveau getteur
// replace variable by your variable name

#ifndef ASCALARCONVERTER_HPP
# define ASCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <cmath>
// # include <cfloat>

class AScalarConverter
{
	public:
		virtual		~AScalarConverter(void) = 0;
		static void	convert(std::string input);
};

#endif

#include AScalarConverter.hpp

bool	displayable(char c)
{
	if (c < 32 || c > 126)
		return false;
	else
		return true;
}

void	AScalarConverter::convert(std::string input)
{
	char	c;
	int		i;
	float	f;
	double	d;

	while (1)
	{
	if (input.length() == 1 && displayable((input.c_str())[0]))
	{
		c = reinterpret_cast<char>(input.c_str());
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		break;
	}
	esle if ()
	}

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}