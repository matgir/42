#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Please start program as follow : ./Sed <filename> <string1> <string2>" << std::endl;
		return (1);
	}

	std::string		filename = av[1];
	std::string		newfile = filename + ".replace";
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string 	extracted;
	size_t			found;

	ifs.open(newfile.c_str());
	if (ifs)
	{
		ifs.close();
		extracted = "bis_" + newfile;
		std::rename(newfile.c_str(), extracted.c_str());
	}
	ifs.open(filename.c_str());
	if (!ifs)
	{
		std::cout << filename << " : Could not be open, try again" << std::endl;
		return (1);
	}
	else if (s1.empty())
	{
		std::cout << "Please enter valid <string1>" << std::endl;
		ifs.close();
		return (1);
	}
	ofs.open(newfile.c_str(), std::fstream::app);
	if (!ofs)
	{
		std::cout << newfile << " : Could not be open, try again" << std::endl;
		ifs.close();
		return (1);
	}
	while (std::getline(ifs, extracted, '\n'))
	{
			found = extracted.find(s1);
			while (found != std::string::npos)
			{
				extracted.erase(found, s1.length());
				extracted.insert(found, s2);
				found = extracted.find(s1, found + s2.length());
			}
			if (ifs.eof())
				ofs << extracted;
			else
				ofs << extracted << std::endl;
	}
	ifs.close();
	ofs.close();
}