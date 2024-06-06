#include "PmergeMe.hpp"

template <typename T>
int	binarySearch(std::pair<int, int> myPair, T myContainer)
{
	int	L = 0;
	int	R = 0;

	if (myPair.second == -1)
		R = myContainer.size() - 1;
	else
	{
		while (myPair.second != myContainer[R])
			R++;
		R--;
	}

	int	m = 0;

	while (L <= R)
	{
		m = (L + R) / 2;
		if (myPair.first > myContainer[m])
			L = m + 1;
		else if (myPair.first < myContainer[m])
			R = m - 1;
		else
			return m;
	}
	return L;
}

std::vector<std::pair<int,int> >	reorganiseMyPairVect(std::vector<std::pair<int, int> > myPairVect, std::vector<int> myVect)
{
	std::vector<std::pair<int, int> >	myNewPairVect;

	for (size_t i = 0; i < myVect.size(); i++)
	{
		for (size_t j = 0; j < myPairVect.size(); j++)
		{
			if (myVect[i] == myPairVect[j].second)
			{
				myNewPairVect.push_back(myPairVect[j]);
				myPairVect.erase(myPairVect.begin() + j);
			}
		}
	}	
	if (!myPairVect.empty())
	{
		if (myPairVect[0].second == -1)
			myNewPairVect.push_back(myPairVect[0]);
	}

	return myNewPairVect;
}

std::vector<int>	algoVect(std::vector<int> myVect)
{
	if (myVect.size() == 1)
		return myVect;
	
	std::vector<std::pair<int, int> >	myPairVect;

	for (size_t i = 1; i < myVect.size(); i += 2)
		myPairVect.push_back(std::make_pair (myVect[i - 1], myVect[i]));

	if (myVect.size() % 2 != 0)
		myPairVect.push_back(std::make_pair(myVect[myVect.size() - 1], -1));

	std::vector<int>	newVect;

	for (size_t i = 0; i < myPairVect.size(); i++)
	{
		if (myPairVect.size() != 1 && myVect.size() % 2 != 0 && i == myPairVect.size() - 1)
			break;
		if (myPairVect[i].first > myPairVect[i].second)
		{
			int	tmp = myPairVect[i].first;
			myPairVect[i].first = myPairVect[i].second;
			myPairVect[i].second = tmp;
		}
		newVect.push_back(myPairVect[i].second);
	}

	myVect = algoVect(newVect);
	myPairVect = reorganiseMyPairVect(myPairVect, myVect);
	myVect.insert(myVect.begin(), myPairVect[0].first);

	int	jacobN_2 = 1;
	int	jacobN_1 = 1;
	for (size_t jacobN = jacobN_1 + (jacobN_2 * 2); jacobN < myPairVect.size(); jacobN = jacobN_1 + (jacobN_2 * 2))
	{
		for (int i = jacobN - 1; i > jacobN_1 - 1; i--)
			myVect.insert(myVect.begin() + binarySearch(myPairVect[i], myVect), myPairVect[i].first);
		jacobN_2 = jacobN_1;
		jacobN_1 = jacobN;
	}
	for (int i = myPairVect.size() - 1; i > jacobN_1 - 1; i--)
		myVect.insert(myVect.begin() + binarySearch(myPairVect[i], myVect), myPairVect[i].first);
	
	return myVect;
}

std::deque<std::pair<int, int> >	reorganiseMyPairDeque(std::deque<std::pair<int, int> > myPairDeque, std::deque<int> myDeque)
{
	std::deque<std::pair<int, int> >	myNewPairDeque;

	for (size_t i = 0; i < myDeque.size(); i++)
	{
		for (size_t j = 0; j < myPairDeque.size(); j++)
		{
			if (myDeque[i] == myPairDeque[j].second)
			{
				myNewPairDeque.push_back(myPairDeque[j]);
				myPairDeque.erase(myPairDeque.begin() + j);
			}
		}
	}
	if (!myPairDeque.empty())
	{
		if (myPairDeque[0].second == -1)
			myNewPairDeque.push_back(myPairDeque[0]);
	}

	return myNewPairDeque;
}

std::deque<int>	algoDeque(std::deque<int> myDeque)
{
	if (myDeque.size() == 1)
		return myDeque;

	std::deque<std::pair<int, int> >	myPairDeque;

	for (size_t i = 1; i < myDeque.size(); i += 2)
		myPairDeque.push_back(std::make_pair (myDeque[i - 1], myDeque[i]));

	if (myDeque.size() % 2 != 0)
		myPairDeque.push_back(std::make_pair (myDeque[myDeque.size() - 1], -1));

	std::deque<int>	newDeque;

	for (size_t i = 0; i < myPairDeque.size(); i++)
	{
		if (myPairDeque.size() != 1 && myDeque.size() % 2 != 0 && i == myPairDeque.size() - 1)
			break;
		if (myPairDeque[i].first > myPairDeque[i].second)
		{
			int	tmp = myPairDeque[i].first;
			myPairDeque[i].first = myPairDeque[i].second;
			myPairDeque[i].second = tmp;
		}
		newDeque.push_back(myPairDeque[i].second);
	}

	myDeque = algoDeque(newDeque);
	myPairDeque = reorganiseMyPairDeque(myPairDeque, myDeque);
	myDeque.insert(myDeque.begin(), myPairDeque[0].first);

	int	jacobN_2 = 1;
	int	jacobN_1 = 1;
	for (size_t jacobN = jacobN_1 + (jacobN_2 * 2); jacobN < myPairDeque.size(); jacobN = jacobN_1 + (jacobN_2 * 2))
	{
		for (int i = jacobN - 1; i > jacobN_1 - 1; i--)
			myDeque.insert(myDeque.begin() + binarySearch(myPairDeque[i], myDeque), myPairDeque[i].first);
		jacobN_2 = jacobN_1;
		jacobN_1 = jacobN;
	}
	for (int i = myPairDeque.size() - 1; i > jacobN_1 - 1; i--)
		myDeque.insert(myDeque.begin() + binarySearch(myPairDeque[i], myDeque), myPairDeque[i].first);
	
	return myDeque;
}