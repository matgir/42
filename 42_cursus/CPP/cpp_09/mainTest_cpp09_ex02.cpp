#include <iostream>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <math.h>

int	binarySearch(std::pair<int, int> myPair, std::vector<int> myVect)
{
	int	L = 0;
	int	R = 0;

	while (myPair.second != myVect[R])
		R++;
	R--;

	int	m = 0;

	while (L <= R)
	{
		m = (L + R) / 2;
		if (myPair.first > myVect[m])
			L = m + 1;
		else if (myPair.first < myVect[m])
			R = m - 1;
		else
			return m;
	}
	std::cout << "returning L" << std::endl;
	return L;
}

int	main(int argc, char ** argv)
{
	(void)argc;

	std::vector<int>	myVect;

	for (int i = 1; argv[i]; i++)
		myVect.push_back(atoi(argv[i]));

	std::pair<int, int>	myPair;

	myPair.first = 10;
	myPair.second = 11;

	for (int i = 0; myVect[i]; i++)
		std::cout << myVect[i];
	std::cout << std::endl;

	myVect.insert(myVect.begin() + binarySearch(myPair, myVect), myPair.first);

	for (int i = 0; myVect[i]; i++)
		std::cout << myVect[i];
	std::cout << std::endl;

	return 1;
}