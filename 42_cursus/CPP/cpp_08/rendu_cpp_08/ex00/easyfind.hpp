#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <algorithm>

template <typename T>
typename T::iterator	easyfind(T & container, const int toFind)
{
	typename T::iterator	it = find(container.begin(), container.end(), toFind);
	
	if (it != container.end())
		return it;
	throw std::out_of_range("The value is not present in the container you send !");
}

#endif