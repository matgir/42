#include "BitcoinExchange.hpp"
// #include <iostream>
#include <fstream>
#include <filesystem>
// #include <string>

int	main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cerr << "Not the right number of argument : <./btc file.txt>" << std::endl;
		return 1;
	}

	std::ifstream	inputcsv;
	
	inputcsv.open(argv[1]);
	if (!inputcsv)
	{
		std::cout << argv[1] << " : could not be open, choose another" << std::endl;
		return 1;
	}
	if (inputcsv.eof())
	{
		std::cout << argv[1] << " : file is empty, choose another" << std::endl;
		return 1;
	}
	
}