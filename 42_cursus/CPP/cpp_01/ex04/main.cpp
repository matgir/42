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
	// std::ifstream	ifs;
	std::string		newfile = filename + ".replace";
	std::ifstream	ifs(filename.c_str());
	std::ofstream	ofs(newfile.c_str(), std::fstream::app);
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string 	extracted;
	// std::string 	to_add;
	size_t			found;

	// ifs.open(filename.c_str());
	// if (!ifs/*  || !ifs.gcount() */) // find a way to check if file is empty
	if (!ifs.is_open())
	{
		std::cout << filename << " : Could not be open, try again" << std::endl;
		return (1);
	}
	else if (s1.empty()/*  || s2.empty() */)
	{
		std::cout << "Please enter valid <string1> and/or <string2>" << std::endl;
		ifs.close();
		return (1);
	}
	// else
	// std::cout << extract << std::endl;
	// peut etre utiliser read, comme gnl pour voir les '\n'
	while (std::getline(ifs, extracted))
	{
			found = extracted.find(s1);
			while (found != std::string::npos)
			{
				extracted.erase(found, s1.length());
				extracted.insert(found, s2);
				found = extracted.find(s1, found + s2.length());
			}
			std::cout << extracted.find('\t') << std::endl;//
			ofs << extracted << std::endl;
	}
	ifs.close();
	ofs.close();
}