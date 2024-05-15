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

	(void)argv;//

	std::map<std::string, float>	mapCsv = mapFromCsv();
	std::string						extracted = lineTo

	return 0;
}