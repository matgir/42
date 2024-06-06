#include "PmergeMe.hpp"

int	main(int argc, char ** argv)
{
	if (!checkArg(argv, argc))
		return 1;

	std::vector<int>	myVect;
	std::deque<int>		myDeque;

	for (int i = 1; argv[i]; i++)
	{
		myVect.push_back(atoi(argv[i]));
		myDeque.push_back(atoi(argv[i]));
	}
	time_t	timeStampBeginning = getTimeInMs();
	myVect = algoVect(myVect);
	time_t	timeStampEnd = getTimeInMs();
	double	diffInSecondsVect = (timeStampEnd - timeStampBeginning);

	timeStampBeginning = getTimeInMs();
	myDeque = algoDeque(myDeque);
	timeStampEnd = getTimeInMs();
	double	diffInSecondsDeque = (timeStampEnd - timeStampBeginning);

	std::cout << "Before : ";
	for (int i = 1; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	std::cout << "After : ";
	for (size_t i = 0; i < myVect.size(); i++)
		std::cout << myVect[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : ";
	std::cout << diffInSecondsVect / 1000 << " microseconds" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : ";
	std::cout << diffInSecondsDeque / 1000 << " microseconds" << std::endl;

	return 1;
}
