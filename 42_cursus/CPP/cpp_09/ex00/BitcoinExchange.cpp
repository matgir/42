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
	for (unsigned long i = 0; str[i]; i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

std::string		lineToUse(std::string extracted)
{
	// std::cout << extracted.substr(0, 4) << std::endl;//
	// std::cout << extracted.substr(5, 2) << std::endl;//
	// std::cout << extracted.substr(8, 2) << std::endl;//
	if (extracted.size() < 14 || extracted.substr(10, 3) != " | "
		|| extracted[4] != '-' || extracted[7] != '-' || !is_num(extracted.substr(0, 4))
		|| !is_num(extracted.substr(5, 2)) || !is_num(extracted.substr(8, 2)))
	{
		std::cout << "Error : bad input => " << extracted << std::endl;
		return "continue";
	}
	// else if ()
	return extracted;
}
