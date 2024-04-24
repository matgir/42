#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template<typename T>
class	Array
{
	public:
		Array<T>(void);
		Array<T>(unsigned int i);
		Array<T>(Array const & copy);

		&operator=(Array const & assign);
		&operator[](unsigned int i);

		unsigned int	size(void)const;//

		class	IndexOutOfRangeException : public std::exception
		{
			public:
				virtual const char *	what()const throw()
					return ("Index out of range !");
		};

	private:
		T *				_array;
		unsigned int	_size;
};

#endif

#include "Array.hpp"

Array::Array<T>(void)
{
	_array = NULL;
	_size = 0;
}

Array::Array<T>(unsigned int i)
{
	_array = new T[i];
	_size = i;
}

Array::Array(Array const & copy)
{
	_size = copy.size();
	_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		_array[i] = copy._array[i];
}

Array	&Array::operator=(Array const & assign)
{
	if (this != assign)
	{
		delete this->_array[];
		_size = assign.size();
		_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			_array[i] = assign._array[i];
	}
	return *this;
}

T	&Array::operator[](unsigned int i)
{
	if (i < 0 || i > this->_size)
		throw Array::IndexOutOfRangeException();
	return this->_array[i];
}
