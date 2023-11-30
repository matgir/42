#include "Fixed.hpp"

const int	Fixed::_binary_point = 8;

Fixed::Fixed(void) : _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}


Fixed	&Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs)
		this->_raw_bits = rhs.getRawBits();

	return *this;
}

//return the raw value of the fixed point number value
int		Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->_raw_bits;
}

//sets the raw value of the fixed point number
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw_bits = raw;
	return;
}