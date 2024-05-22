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

bool	isValidIntFloat(std::string str)
{
	{
		unsigned int	negSign = 0;
		unsigned int	f = 0;
		unsigned int	dot = 0;

		for (unsigned long i = 0; str[i]; i++)
			if (str[i] == '-')
				negSign++;
		for (unsigned long i = 0; str[i]; i++)
			if (str[i] == 'f')
				f++;
		for (unsigned long i = 0; str[i]; i++)
			if (str[i] == '.')
				dot++;
		
		if (negSign > 1 || f > 1 || dot > 1)
			return false;
		else if (negSign == 1 && str.find('-') == 0)

			
		if (negSign > 1 || (negSign == 1 && str.find('-') == 0))
			return false;
		if (f > 1 || (f == 1 && str[str.length() - 1] == 'f'))
			return false;
		std::cout << "HERE\n";//
		str.erase(0, 1);
		std::cout << str[str.length() - 1] << std::endl; //
		str.erase(str.length() - 1, 1);
		std::cout << "HERE AS WELL\n";//
	}
	{

	}
	{
		// dot;
	}
	{
		// is_num;
	}
	return true;
}

std::string		lineToUse(std::string extracted)
{
	// std::cout << extracted.substr(0, 4) << std::endl;//
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
	// else if ()
	return extracted;
}
