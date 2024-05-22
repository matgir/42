#include "BitcoinExchange.hpp"

/* check data.csv */
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
		mapCsv[extracted.substr(0, 10)] = atoi((extracted.substr(11, std::string::npos).c_str()));
		if (inputCsv.eof())
			break;
	}
	// for (std::map<std::string, float>::iterator it = mapCsv.begin(); it != mapCsv.end(); it++)//
		// std::cout << it->first << "    " << it->second << std::endl;//

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
	// std::cout << str << std::endl;//
	for (unsigned long i = 0; str[i]; i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

bool	isValidIntFloat(std::string str)
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
		str.erase(0, 1);
	if (dot == 1)
		str.erase(str.find('.'), 1);
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
	else if (month == (1 || 3 || 5 || 7 || 8 || 10 || 12))
		if (day > 31)
			return false;
	else if (month == (2 || 4 || 6 || 9 || 11))
		// #############################
	// std::cout << year << " " << month << " " << day << std::endl;//
	return true;
}

std::string		lineToUse(std::string extracted)
{
	// std::cout << extracted.substr(0, 10) << std::endl;//
	// std::cout << extracted.substr(5, 2) << std::endl;//
	// std::cout << extracted.substr(8, 2) << std::endl;//
	if (extracted.size() < 14 || extracted.substr(10, 3) != " | "
		|| extracted[4] != '-' || extracted[7] != '-'
		|| !is_num(extracted.substr(0, 4)) || !is_num(extracted.substr(5, 2))
		|| !is_num(extracted.substr(8, 2))
		|| !isValidIntFloat(extracted.substr(13, std::string::npos)))
	{
		std::cout << "Error : bad input => " << extracted << std::endl;
		return "continue";
	}
	else if (!isValidDate(extracted.substr(0, 10)))
	{
		std::cout << "Error : invalid date => " << extracted << std::endl;
		return "continue";
	}
	return extracted;
}
