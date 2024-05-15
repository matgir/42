#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <map>
#include <vector>

int	main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cerr << "Not the right number of argument : <./btc file.txt>" << std::endl;
		return 1;
	}

	/* check argv[1] */

	std::ifstream	inputTxt;

	inputTxt.open(argv[1]);
	if (!inputTxt)
	{
		std::cout << argv[1] << " : could not be open, choose another *.txt" << std::endl;
		return 1;
	}
	if (inputTxt.eof())
	{
		std::cout << argv[1] << " : file empty, choose another *.txt" << std::endl;
		return 1;
	}

	std::map<std::string, int>	mapTxt;
	std::string					extracted;

	while (std::getline(inputTxt, extracted, "\n"))
	{
	}


	/* check data.csv */

	std::ifstream	inputCsv;
	
	inputcsv.open(/* #### */);
	if (!inputcsv)
	{
		std::cout << /* #### */ << " : could not be open, choose another" << std::endl;
		return 1;
	}
	if (inputcsv.eof())
	{
		std::cout << /* #### */ << " : file is empty, choose another" << std::endl;
		return 1;
	}

}