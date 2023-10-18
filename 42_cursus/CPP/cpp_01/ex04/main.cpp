#include <string>
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Please start program as follow : ./Sed <filename> <string1> <string2>" << std::endl;
		return (1);
	}

	std::string		filename = av[1];
	std::ifstream	ifs;
	std::string		s1 = av[2];
	std::string		s2 = av[3];

	ifs.open(filename.c_str());
	if (!ifs/*  || !ifs.gcount() */)
	{
		std::cout << filename << " : Could not be open or is empty, try again" << std::endl;
		return (1);
	}
	else if (s1.empty() || s2.empty())
	{
		std::cout << "Please enter valid <string1> and/or <string2>" << std::endl;
		return (1);
	}
	// else
		// GODD


}