#include <iostream>
// #include <string>

template<typename T>
void	iter(T * array, size_t size, void (*f)(T &))
{
	for (int i = 0; i < size, i++)
	{
		f(array[i]);
	}
	return;
}

template<typename T>
void	showMe(T & toPrint)
{
	std::cout << toPrint << std::endl;
	return;
}