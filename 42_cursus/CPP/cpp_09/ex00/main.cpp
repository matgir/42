#include "BitcoinExchange.hpp"
#include <filesystem>
#include <string>
#include <vector>
#include <math.h>

int	main(int argc, char ** argv)
{
	std::cout << std::endl << std::endl;//
	if (argc != 2)
	{
		std::cerr << "Not the right number of argument : <./btc file.txt>" << std::endl;
		std::cout << std::endl << std::endl;//
		return 1;
	}

	// (void)argv;//


	std::string						inputName(argv[1]);

	checkStream(inputName);

	std::ifstream					inputTxt(inputName);
	std::string						extracted;

	// inputTxt.open(inputName);
	std::getline(inputTxt, extracted);
	std::map<std::string, float>	mapCsv = mapFromCsv();

	bool			isFloat = false;
	// std::string		date;
	// unsigned int	value;

	while (std::getline(inputTxt, extracted))
	{
		isFloat = false;
		if (lineToUse(extracted, &isFloat))
		{//
			// std::cout << "EXTRACTED		" << extracted << std::endl; //
			giveTheResult(extracted, &isFloat, mapCsv);
		}//
	}

	inputTxt.close();

	std::cout << std::endl << std::endl;//
	return 0;
}