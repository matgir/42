#include "BitcoinExchange.hpp"
// #include <iostream>
// #include <fstream>
#include <filesystem>

int	main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cerr << "Not the right number of argument : <./btc file.txt>" << std::endl;
		return 1;
	}

	std::ifstream	inputcsv;
}