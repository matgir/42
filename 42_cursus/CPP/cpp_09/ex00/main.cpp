#include "BitcoinExchange.hpp"
#include <filesystem>
#include <string>
#include <vector>
#include <math.h>

int	main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cerr << "Not the right number of argument : <./btc file.txt>" << std::endl;
		return 1;
	}

	// (void)argv;//


	std::map<std::string, float>	mapCsv = mapFromCsv();
	std::string						inputName(argv[1]);
	checkStream(inputName);
	std::ifstream					inputTxt(inputName);
	std::string						extracted;

	// inputTxt.open(inputName);
	std::getline(inputTxt, extracted);

	while (std::getline(inputTxt, extracted))
	{
	}

	return 0;
}