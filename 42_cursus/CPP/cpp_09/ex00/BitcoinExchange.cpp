#include "BitcoinExchange.hpp"

std::map<std::string, float>	mapFromCsv(void)
{
	std::ifstream	inputCsv;

	inputCsv.open("data.csv");
	if (!inputCsv)
	{
		std::cout << "data.csv : could not be open" << std::endl;
		exit(0);
	}
	if (inputCsv.eof())
	{
		std::cout << "data.csv : file empty" << std::endl;
		inputCsv.close();
		exit(0);
	}

	std::map<std::string, float>	mapCsv;
	std::string						extracted;

	std::getline(inputCsv, extracted, '\n');
	while (std::getline(inputCsv, extracted, '\n'))
	{
		mapCsv[extracted.substr(0, 10)] = atof((extracted.substr(11, std::string::npos).c_str()));
		if (inputCsv.eof())
			break;
	}
	inputCsv.close();
	return mapCsv;
}

void	checkStream(std::string inputName)
{
	std::ifstream	inputTxt;

	inputTxt.open(inputName);
	if (!inputTxt)
	{
		std::cout << inputName << " : could not be open, select another" << std::endl;
		exit (0);
	}
	if (inputTxt.eof())
	{
		std::cout << inputName << " : file empty, select another" << std::endl;
		inputTxt.close();
		exit (0);
	}
	inputTxt.close();
	return;
}

bool	is_num(std::string str)
{
	for (unsigned long i = 0; str[i]; i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

bool	isValidIntFloat(std::string str, bool * isNeg, bool * isFloat)
{
	unsigned int	negSign = 0;
	unsigned int	dot = 0;

	for (unsigned long i = 0; str[i]; i++)
		if (str[i] == '-')
			negSign++;
	for (unsigned long i = 0; str[i]; i++)
		if (str[i] == '.')
			dot++;

	if (negSign > 1 || dot > 1)
		return false;
	if (negSign == 1 && str.find('-') == 0)
	{
		str.erase(0, 1);
		*isNeg = true;
	}
	if (dot == 1)
	{
		str.erase(str.find('.'), 1);
		*isFloat = true;
	}
	if (!is_num(str) || str.empty())
		return false;
	return true;
}

bool	isValidDate(std::string date)
{
	unsigned int	year = std::atoi((date.substr(0, 4)).c_str());
	unsigned int	month = std::atoi((date.substr(5, 2)).c_str());
	unsigned int	day = std::atoi((date.substr(8, 2)).c_str());

	if (year < 0 || year > 3000 || month < 1 || month > 12 || day < 1)
		return false;
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
			|| month == 10 || month == 12)
	{
		if (day > 31)
			return false;
	}
	else if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
		if (month == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0)
					|| (year % 100 == 0 && year % 400 == 0))
			{
				if (day > 29)
					return false;
			}
			else
			{
				if (day > 28)
					return false;
			}
		}
	}
	return true;
}

bool	wasBitcoinHere(std::string date)
{
	unsigned int	year = std::atoi((date.substr(0, 4)).c_str());
	unsigned int	month = std::atoi((date.substr(5, 2)).c_str());
	unsigned int	day = std::atoi((date.substr(8, 2)).c_str());

	if (year < 2009 || (year == 2009 && month < 1) || (year == 2009 && month == 1 && day < 2))
		return false;
	return true;
}

bool		lineToUse(std::string extracted, bool * isFloat)
{
	bool	isNeg = false;

	if (extracted.size() < 14 || extracted.substr(10, 3) != " | "
			|| extracted[4] != '-' || extracted[7] != '-'
			|| !is_num(extracted.substr(0, 4)) || !is_num(extracted.substr(5, 2))
			|| !is_num(extracted.substr(8, 2))
			|| !isValidIntFloat(extracted.substr(13, std::string::npos), &isNeg, isFloat))
	{
		std::cout << "Error : bad input => " << extracted << std::endl;
		return false;
	}
	else if (!isValidDate(extracted.substr(0, 10)))
	{
		std::cout << "Error : invalid date => " << extracted << std::endl;
		return false;
	}
	else if (!wasBitcoinHere(extracted.substr(0, 10)))
	{
		std::cout << "Error : no prior information to this date => " << extracted << std::endl;
		return false;
	}
	else if (isNeg)
	{
		std::cout << "Error : not a positive number => " << extracted << std::endl;
		return false;
	}
	else if ((isFloat
				&& std::atof((extracted.substr(13, std::string::npos)).c_str()) > 1000)
			|| std::atol((extracted.substr(13, std::string::npos)).c_str()) > 1000)
	{
		std::cout << "Error : too large a number => " << extracted << std::endl;
		return false;
	}
	return true;
}

void	giveTheResult(std::string str, bool * isFloat, std::map<std::string, float> mapCsv)
{

	std::string		date = str.substr(0, 10);
	float			value;

	if (*isFloat == 1)
		value = std::atof((str.substr(13, std::string::npos)).c_str());
	else
		value = std::atoi((str.substr(13, std::string::npos)).c_str());

	std::map<std::string, float>::iterator	it;

	it = mapCsv.find(date);
	if (it != mapCsv.end())
	{
		std::cout << date << " => " << value << " = ";
		std::cout << value * it->second << std::endl;
	}
	else
	{
		std::map<std::string, float>::key_compare	compare = mapCsv.key_comp();

		it = mapCsv.begin();
		if (compare(mapCsv.rbegin()->first, date))
		{
			std::cout << date << " => " << value << " = ";
			std::cout << value * mapCsv.rbegin()->second << std::endl;
		}
		else
		{
			while (compare(it->first, date))
			{++it;}
			--it;
			std::cout << date << " => " << value << " = ";
			std::cout << value * it->second << std::endl;
		}
	}
	*isFloat = false;
	return;
}
