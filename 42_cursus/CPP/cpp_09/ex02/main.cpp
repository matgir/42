#include "PmergeMe.hpp"

int	main(int argc, char ** argv)
{
	// check error number list
	// premier time stamp

	(void)argc;//

	std::vector<int>	myVect;

	for (int i = 1; argv[i]; i++)
		myVect.push_back(atoi(argv[i]));

	for (size_t i = 0; i < myVect.size(); i++)//
		std::cout << myVect[i] << " ";//
	std::cout << std::endl;//

	myVect = algoVect(myVect);

	for (size_t i = 0; i < myVect.size(); i++)//
		std::cout << myVect[i] << " ";//
	std::cout << std::endl;//

}