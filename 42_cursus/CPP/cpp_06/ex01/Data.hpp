// replace canonical by your class name
// replace getuint(void)const par nouveau getteur
// replace variable by your variable name

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	public:

		Data(void);
		Data(Data const & copy);
		virtual ~Data(void);

		Data	&operator=(Data const & assign);

		unsigned int	getuint(void)const;//

	private:

		unsigned int	_uint;//
};

#endif

#include "Data.hpp"

Data::Data(void) : _uint(0)
{
	std::cout << "Data default constructor called" << std::endl;
	return;
}

Data::Data(Data const & copy)
{
	std::cout << "Data copy constructor called" << std::endl;
	this->_uint = copy.getuint();
	return;
}

Data::~Data(void)
{
	std::cout << "Data destructor called" << std::endl;
	return;
}

Data	&Data::operator=(Data const & assign)
{
	std::cout << "Data assignment operator called" << std::endl;

	if (this != &assign)
		this->_uint = assign.getuint();

	return *this;
}

int	Data::getuint(void)const
{
	return this->_uint;
}