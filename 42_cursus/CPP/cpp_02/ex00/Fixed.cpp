#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedpointnumber(0)
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
		this->_fixedpointnumber = rhs.getRawBits();

	return *this;
}

int		Fixed::getRawBits(void)const
{

}

void	Fixed::setRawBits(int const raw)
{

}