#include "Fixed.hpp"

const int	Fixed::_binary_point = 8;

Fixed::Fixed(void) : _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw_bits = i << _binary_point;
	return;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw_bits = roundf(f * (1 << _binary_point));
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}


Fixed	&Fixed::operator=(Fixed const & copie)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &copie)
		this->_raw_bits = copie.getRawBits();

	return *this;
}

//return the raw value of the fixed point number value
int		Fixed::getRawBits(void)const
{
	return this->_raw_bits;
}

//sets the raw value of the fixed point number
void	Fixed::setRawBits(int const copie)
{
	this->_raw_bits = copie;
	return;
}

int		Fixed::toInt(void)const
{
	return this->_raw_bits >> this->_binary_point;
}

float	Fixed::toFloat(void)const
{
	return this->_raw_bits / (float)(1 << _binary_point);
}

std::ostream	&operator<<(std::ostream & stream, Fixed const & fixed)
{
	stream << fixed.toFloat();
	return stream;
}