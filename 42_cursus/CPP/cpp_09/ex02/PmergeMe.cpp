#include "PmergeMe.hpp"

std::pair<int, int>	foundValue(int toFind, std::vector<std::pair<int, int> > myPairVect)
{
	for (size_t i = 0; i < myPairVect.size(); i++)
	{
		if (toFind == myPairVect[i].second)
			return myPairVect[i];
	}
	return myPairVect[0];
}

std::vector<std::pair<int,int> >	reorganiseMyPairVect(std::vector<std::pair<int, int> > myPairVect, std::vector<int> myVect)
{
	std::vector<std::pair<int, int> >	myNewPairVect;

	for (size_t i = 0; i < myVect.size(); i++)
		myNewPairVect.push_back(foundValue(myVect[i], myPairVect));
	
	if (myPairVect[myPairVect.size() - 1].second == -1)//
		myNewPairVect.push_back(myPairVect[myPairVect.size() - 1]);//

	return myNewPairVect;
}

int	binarySearch(std::pair<int, int> myPair, std::vector<int> myVect)
{
	int	L = 0;
	int	R = 0;

	if (myPair.second == -1)//
		R = myVect.size() - 1;//
	else//
	{//
		while (myPair.second != myVect[R])
			R++;
		R--;
	}//

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
	return L;
}

std::vector<int>	algoVect(std::vector<int> myVect)
{
	if (myVect.size() == 1)
		return myVect;
	
	std::vector<std::pair<int, int> >	myPairVect;

	/* ADD VERIF IF MYVECT.SIZE() IS ODD THEN DO SOMETHING*/

	for (size_t i = 1; i < myVect.size(); i += 2)
		myPairVect.push_back(std::make_pair (myVect[i - 1], myVect[i]));

	if (myVect.size() % 2 != 0)//
		myPairVect.push_back(std::make_pair(myVect[myVect.size() - 1], -1));//

	std::vector<int>	newVect;

	for (size_t i = 0; i < myPairVect.size(); i++)
	{
		if (myPairVect.size() != 1 && myVect.size() % 2 != 0 && i == myPairVect.size() - 1)//
			break;//
		if (myPairVect[i].first > myPairVect[i].second)
		{
			int	tmp = myPairVect[i].first;
			myPairVect[i].first = myPairVect[i].second;
			myPairVect[i].second = tmp;
		}
		newVect.push_back(myPairVect[i].second);
	}

	myVect = algoVect(newVect);

	std::cout << "HELLO\n";//

	myPairVect = reorganiseMyPairVect(myPairVect, myVect);

	std::vector<int>::iterator	it = myVect.begin();

	// myVect.insert(it, foundValue(it, myPairVect));
	myVect.insert(it, myPairVect[0].first);

	int	jacobN_2 = 1;
	int	jacobN_1 = 1;
	for (size_t jacobN = jacobN_1 + (jacobN_2 * 2); jacobN < myPairVect.size(); jacobN = jacobN_1 + (jacobN_2 * 2))
	{
		for (int i = jacobN - 1; i > jacobN_1 - 1; i--)
			myVect.insert(it + binarySearch(myPairVect[i], myVect), myPairVect[i].first);
		jacobN_2 = jacobN_1;
		jacobN_1 = jacobN;
	}
	for (int i = myPairVect.size() - 1; i > jacobN_1 -1; i--)
		myVect.insert(it + binarySearch(myPairVect[i], myVect), myPairVect[i].first);
	
	return myVect;
}
