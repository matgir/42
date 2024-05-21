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

std::ifstream *	inputFromTxt(std::string inputName)
{
	std::ifstream *	inputTxt;

	inputTxt->open(inputName);
	if (!inputTxt)
	{
		std::cout << inputName << " : could not be open, select another" << std::endl;
		exit (0);
	}
	if (inputTxt->eof())
	{
		std::cout << inputName << " : file empty, select another" << std::endl;
		inputTxt->close();
		exit (0);
	}

	return inputTxt;
}

std::string		lineToUse(std::ifstream * inputTxt)
{
	std::string	extracted;

	std::getline(*inputTxt, extracted, '\n');

	return extracted;
}
