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
	for (int i = 0; input[i]; i++)
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
	for (int i = 0; input[i]; i++)
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
	while (it != input.end())
		it = input.erase(static_cast<std::string::iterator>("f"));
	it = input.begin();
	while (it != input.end())
		it = input.erase(static_cast<std::string::iterator>("."));
	for (int i = 0; input[i]; i++)
		if (!std::isdigit(input[i]))
			return false;
	return true;
}

bool	neg(std::string input)
{
	int	neg_sign = 0;
	for (int i = 0; input[i]; i++)
		if (input[i] == '-')
			neg_sign++;
	if (neg_sign == 0 || (neg_sign == 1 && input.find('-') == 0))
		return true;
	else
		return false;
}

void	AScalarConverter::convert(std::string input)
{
	char	c;
	int		i;
	float	f;
	double	d;
	// int		point;
	// int		f_float;

	// point = point_ocurence(input);
	// f_float = f_ocurence(input);

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
	else if (f_ocurence(input) && dot_ocurence(input) && neg(input) && is_num(input))
	{
		// gerer -inff +inff nanf
		f = static_cast<float>(std::atof(input.c_str()));
		d = static_cast<double>(f);
		// implemeter verif pour nanf avant conversion en int et c
		i = static_cast<int>(f);
		c = static_cast<char>(i);
		break;
	}
	else if (dot_ocurence(input) && neg(input) && is_num(input))
	{
		// gerer -inf +inf nan
		d = std::atof(input.c_str());
		f = static_cast<float>(d);
		// implemeter verif pour nan avant conversion en int et c
		i = static_cast<int>(d);
		c = static_cast<char>(i);
		break;
	}
	else if (neg(input) && is_num(input))
	{
		i = atoi(input.c_str());
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
		break;
	}
	else
	{
		/* savoir quoi faire quand ca ne rentre dans aucune des cases */
	}
	}

	if (displayable(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non Displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}