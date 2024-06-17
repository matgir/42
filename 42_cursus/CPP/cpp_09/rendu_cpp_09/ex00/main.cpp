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
	std::string						inputName(argv[1]);
	bool							isThereProblem = false;

	checkStream(inputName, &isThereProblem);
	if (isThereProblem == true)
		return 1;	

	std::ifstream					inputTxt(inputName.c_str());
	std::string						extracted;
	std::map<std::string, float>	mapCsv = mapFromCsv(&isThereProblem);

	if (isThereProblem == true)
		return 1;	

	bool							isFloat = false;

	std::getline(inputTxt, extracted);
	while (std::getline(inputTxt, extracted))
	{
		isFloat = false;
		if (lineToUse(extracted, &isFloat))
			giveTheResult(extracted, &isFloat, mapCsv);
	}
	inputTxt.close();
	std::cout << std::endl << std::endl;//
	return 1;
}