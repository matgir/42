#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>	
# include <cstddef>

template<typename T>
void	iter(T * array, std::size_t size, void (*f)(T &))
{
	for (std::size_t i = 0; i < size; i++)
	{
		(*f)(array[i]);
	}
	return;
}

template<typename T>
void	showMe(T & toPrint)
{
	std::cout << toPrint << std::endl;
	return;
}

#endif