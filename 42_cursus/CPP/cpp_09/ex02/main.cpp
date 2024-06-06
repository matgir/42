#include "PmergeMe.hpp"

time_t	getTimeInMs(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}

bool	checkArg(char ** argv, int argc)
{
	if (argc < 2)
	{
		std::cout << "Error : no sequence to sort" << std::endl;
		return false;
	}
	for (int j = 1; argv[j]; j++)
	{
		for (int i = 0; argv[j][i]; i++)
		{
			if (!isdigit(argv[j][i]))
			{
				std::cout << "Error : There is not only number or a negative number in the sequence" << std::endl;
				return false;
			}
		}
		long int	value = atol(argv[j]);
		if (value > 2147483647)
		{
			std::cout << "Error : A number in the sequence is to big to fit in an integer" << std::endl;
			return false;
		}
	}
	return true;
}

int	main(int argc, char ** argv)
{
	//##### check error number list

	if (!checkArg(argv, argc))
		return 0;

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
