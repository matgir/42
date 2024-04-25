#include "AScalarConverter.hpp"

bool	displayable(char c)
{
	if (c < 32 || c > 126)
		return false;
	else
		return true;
}

bool	dot_ocurence(std::string input)
{
	int	point = 0;
	for (unsigned long i = 0; input[i]; i++)
		if (input[i] == '.')
			point++;
	if (point == 1)
		return true;
	else
		return false;
}

bool	f_ocurence(std::string input)
{
	int	f_float = 0;
	for (unsigned long i = 0; input[i]; i++)
		if (input[i] == 'f')
			f_float++;
	if (f_float == 1 && (input.rfind('f') == input.length() - 1))
		return true;
	else
		return false;
}

bool	is_num(std::string input)
{
	std::string::iterator	it = input.begin();

	while (input.find_first_of('f') != std::string::npos)
		it = input.erase(input.begin() + static_cast<long>(input.find_first_of('f')));
	it = input.begin();
	while (input.find_first_of('.') != std::string::npos)
		it = input.erase(input.begin() + static_cast<long>(input.find_first_of('.')));
	it = input.begin();
	while (input.find_first_of('-') != std::string::npos)
		it = input.erase(input.begin() + static_cast<long>(input.find_first_of('-')));
	for (unsigned long i = 0; input[i]; i++)
		if (!std::isdigit(input[i]))
			return false;
	return true;
}

bool	neg(std::string input)
{
	int	neg_sign = 0;
	for (unsigned long i = 0; input[i]; i++)
		if (input[i] == '-')
			neg_sign++;
	if (neg_sign == 0 || (neg_sign == 1 && input.find('-') == 0))
		return true;
	else
		return false;
}

bool	asciiRange(char c)
{
	if (c < 0 || c > 127)
		return true;
	else
		return false;
}

void	output(char c, int i, float f, double d)
{
	// std::cout << "In Output" << std::endl;//
	// std::cout << f << std::endl; //
	// if (asciiRange(c)/*  || f == INFINITY || f == -INFINITY */)
	if (c == -1)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else if (displayable(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
	}
	else
	{
		std::cout << "char: Non Displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
	}
	std::cout << "float: " << f << (f == static_cast<float>(i) ? ".0f" : "f") << std::endl;
	std::cout << "double: " << d << (d == static_cast<double>(i) ? ".0" : "") << std::endl;
}

bool	pseudoLiterals(std::string input)
{
	if (input == "nan")
	{
		output(static_cast<char>(-1), static_cast<int>(-1),
				static_cast<float>(NAN), static_cast<double>(NAN));
		return true;
	}
	else if (input == "nanf")
	{
		output(static_cast<char>(-1), static_cast<int>(-1),
				static_cast<float>(NAN), static_cast<double>(NAN));
		return true;
	}
	else if (input == "inf")
	{
		output(static_cast<char>(-1), static_cast<int>(-1),
				static_cast<float>(INFINITY), static_cast<double>(INFINITY));
		return true;
	}
	else if (input == "inff")
	{
		output(static_cast<char>(-1), static_cast<int>(-1),
				static_cast<float>(INFINITY), static_cast<double>(INFINITY));
		return true;
	}
	else if (input == "-inf")
	{
		output(static_cast<char>(-1), static_cast<int>(-1),
				static_cast<float>(-INFINITY), static_cast<double>(-INFINITY));
		return true;
	}
	else if (input == "-inff")
	{
		output(static_cast<char>(-1), static_cast<int>(-1),
				static_cast<float>(-INFINITY), static_cast<double>(-INFINITY));
		return true;
	}
	return false;
}

void	AScalarConverter::convert(std::string input)
{
	char	c;
	int		i;
	float	f;
	double	d;

	while (1)
	{
		if (pseudoLiterals(input))
			break;
		/*	#### char ####	*/
		else if (input.length() == 1 && displayable((input.c_str())[0]) && !is_num(input))
		{
			c = reinterpret_cast<char>(input.c_str()[0]);
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			std::cout << "CHAR" << std::endl; //
			output(c, i, f, d);
			break;
		}
		/*	#### float ####	*/
		else if ((f_ocurence(input) || (f_ocurence(input) && dot_ocurence(input))) && neg(input) && is_num(input))
		{
			// long int n = atol(input.c_str());
			// if ( n > FLT_MAX || n < -FLT_MAX)
			//...
			f = static_cast<float>(std::atof(input.c_str()));
			// f = INFINITY; //
			// f = NAN;//
			d = static_cast<double>(f);
			i = static_cast<int>(f);
			c = static_cast<char>(i);
			std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "FLOAT" << std::endl; //
			std::cout << f << std::endl; //
			output(c, i, f, d);
			break;
		}
		/*	#### double ####	*/
		else if (dot_ocurence(input) && neg(input) && is_num(input))
		{
			// long int n = atol(input.c_str());
			// if ( n > DBL_MAX || n < -DBL_MAX)
			//...


			d = std::atof(input.c_str());
			// d = -INFINITY; //
			// d = NAN;//
			// if (d == NAN)//
			// break;//
			f = static_cast<float>(d);
			i = static_cast<int>(d);
			c = static_cast<char>(i);
			std::cout << "DOUBLE" << std::endl; //
			output(c, i, f, d);
			break;
		}
		/*	#### int ####	*/
		else if (neg(input) && is_num(input))
		{

			// long int n = atol(input.c_str());
			// if ( n > INT_MAX || n < INT_MIN)
			// std::cout << " overflow " << std::endl;
			// else
			// {
			i = atoi(input.c_str());
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			std::cout << "INT" << std::endl; //
			output(c, i, f, d);
			// }
			break;
		}
		// else
		// {
		// 	std::cout << "char: impossible\nint: impossible" << std::endl;
		// 	std::cout << "float: nanf\ndouble: nan" << std::endl;
		// 	break;
		// }
	}
}
