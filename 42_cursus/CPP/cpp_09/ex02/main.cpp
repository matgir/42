#include "PmergeMe.hpp"

int	main(int argc, char ** argv)
{
	//##### check error number list

	(void)argc;//

	std::vector<int>	myVect;
	std::deque<int>		myDeque;

	for (int i = 1; argv[i]; i++)
	{
		myVect.push_back(atoi(argv[i]));
		myDeque.push_back(atoi(argv[i]));
	}
	
	for (size_t i = 0; i < myVect.size(); i++)//
		std::cout << myVect[i] << " ";//
	std::cout << std::endl;//
	for (size_t i = 0; i < myDeque.size(); i++)//
		std::cout << myDeque[i] << " ";//
	std::cout << std::endl;//

	//##### premier time stamp
	myVect = algoVect(myVect);
	//##### dif avec premier time stamp

	//##### duexieme time stamp
	myDeque = algoDeque(myDeque);
	//##### dif avec deuxieme time stamp

	for (size_t i = 0; i < myVect.size(); i++)//
		std::cout << myVect[i] << " ";//
	std::cout << std::endl;//
	for (size_t i = 0; i < myDeque.size(); i++)//
		std::cout << myDeque[i] << " ";//
	std::cout << std::endl;//


	// ##### cout before
	// ##### cout after
	// ##### time first container
	// ##### time seconde container
		/*	Before: 3 5 9 7 4
			After: 3 4 5 7 9
			Time to process a range of 5 elements with std::[..] : 0.00031 us
			Time to process a range of 5 elements with std::[..] : 0.00014 us
			*/
}