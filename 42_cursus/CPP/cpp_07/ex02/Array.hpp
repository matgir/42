#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include <ctime>
# include <cstdlib>

template<typename T>
class	Array
{
	public:
		Array< T >(void)
		{
			_array = NULL;
			_size = 0;
			return;
		}
		Array< T >(unsigned int i)
		{
			_array = new T[i];
			_size = i;
			return;
		}
		Array< T >(Array const & copy)
		{
			_size = copy.size();
			_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				_array[i] = copy._array[i];
			return;
		}
		~Array< T >(void)
		{
			// for (unsigned int i = 0; i < this->_size; i++)
			delete this->_array;
			return;
		}

		class	IndexOutOfRangeException : public std::exception
	{
		public:
			virtual const char *	what() const throw()
			{
				return ("Index out of range !");
			}
	};

		Array			&operator=(Array const & assign)
		{
			if (this != assign)
			{
				delete this->_array;
				_size = assign.size();
				_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					_array[i] = assign._array[i];
			}
			return *this;
		}
		T	&operator[](unsigned int i)const
		{
			if (i < 0 || i >= this->_size)
				throw Array::IndexOutOfRangeException();
			return this->_array[i];
		}

		unsigned int	size(void)const
		{
			return static_cast<int>(this->_size);
		}

	private:
		T *				_array;
		unsigned int	_size;
};

// template<typename T>
// Array::Array< T >(void)

// template<typename T>
// Array::Array< T >(unsigned int i)

// template<typename T>
// Array::Array< T >(Array const & copy)

// Array::~Array(void)

// // template<typename T>
// Array	&Array::operator=(Array const & assign)

// // template<typename T>
// T	&Array::operator[](unsigned int i)

// // template<typename T>
// unsigned int	Array::size(void)const

#endif
