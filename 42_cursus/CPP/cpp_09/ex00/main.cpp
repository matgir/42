#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <map>
#include <vector>
#include <math.h>

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

	std::getline(inputTxt, extracted, '\n');
	std::cout << extracted << std::endl; //
	while (std::getline(inputTxt, extracted, '\n'))
	{
		std::cout << extracted << std::endl; //
		mapTxt[extracted.substr(0, 9)] = atoi((extracted.substr(12, std::string::npos).c_str()));
		if (inputTxt.eof())
			break;
	}
	std::cout << "mapTxt constains :" << std::endl;//
	for (std::map<std::string, int>::iterator it = mapTxt.begin(); it != mapTxt.end(); it++)//
		std::cout << it->first << "    " << it->second << std::endl;//


	/* check data.csv */

	std::ifstream	inputCsv;
	
	// inputcsv.open(/* #### */);
	// if (!inputcsv)
	// {
	// 	std::cout << /* #### */ << " : could not be open, choose another" << std::endl;
	// 	return 1;
	// }
	// if (inputcsv.eof())
	// {
	// 	std::cout << /* #### */ << " : file is empty, choose another" << std::endl;
	// 	return 1;
	// }

}