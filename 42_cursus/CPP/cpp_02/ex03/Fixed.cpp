#include "Fixed.hpp"

const int	Fixed::_binary_point = 8;

//********** Constructor **********//
Fixed::Fixed(void) : _raw_bits(0)
{
	return;
}

Fixed::Fixed(Fixed const & copy)
{
	*this = copy;
	return;
}

Fixed::Fixed(const int i)
{
	this->_raw_bits = i << _binary_point;
	return;
}

Fixed::Fixed(const float f)
{
	this->_raw_bits = roundf(f * (1 << _binary_point));
	return;
}



//********** Destructor **********//
Fixed::~Fixed(void)
{
	return;
}



//********** Comparison **********//
Fixed	&Fixed::operator=(Fixed const & copie)
{

	if (this != &copie)
		this->_raw_bits = copie.getRawBits();

	return *this;
}

bool	Fixed::operator>(Fixed const & compare)const
{
	return this->_raw_bits > compare.getRawBits();
}

bool	Fixed::operator<(Fixed const & compare)const
{
	return this->_raw_bits < compare.getRawBits();
}

bool	Fixed::operator>=(Fixed const & compare)const
{
	return this->_raw_bits >= compare.getRawBits();
}

bool	Fixed::operator<=(Fixed const & compare)const
{
	return this->_raw_bits <= compare.getRawBits();
}

bool	Fixed::operator==(Fixed const & compare)const
{
	return this->_raw_bits == compare.getRawBits();
}

bool	Fixed::operator!=(Fixed const & compare)const
{
	return this->_raw_bits != compare.getRawBits();
}


//********** Modifier **********//
Fixed	Fixed::operator+(Fixed const & modifier)
{
	Fixed	result;

	result.setRawBits(this->_raw_bits + modifier.getRawBits());
	return result;
}

Fixed	Fixed::operator-(Fixed const & modifier)
{
	Fixed	result;

	result.setRawBits(this->_raw_bits - modifier.getRawBits());
	return result;
}

Fixed	Fixed::operator*(Fixed const & modifier)
{
	Fixed	result;

	result.setRawBits((this->_raw_bits * modifier.getRawBits()) >> this->_binary_point);
	return result;
}

Fixed	Fixed::operator/(Fixed const & modifier)
{
	Fixed	result;

	result.setRawBits((this->_raw_bits << this->_binary_point) / modifier.getRawBits());
	return result;
}


//********** Crement **********//
Fixed	&Fixed::operator++(void)
{
	this->_raw_bits++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	this->_raw_bits++;
	return old;
}

Fixed	&Fixed::operator--(void)
{
	this->_raw_bits--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	this->_raw_bits--;
	return old;
}


//********** Functions **********//
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

Fixed	&Fixed::min(Fixed & a, Fixed & b)
{
	return a < b ? a : b;
}

const Fixed	&Fixed::min(Fixed const & a, Fixed const & b)
{
	// std::cout << "(in const min)";
	return a < b ? a : b;
}

Fixed	&Fixed::max(Fixed & a, Fixed & b)
{
	return a > b ? a : b;
}

const Fixed	&Fixed::max(Fixed const & a, Fixed const & b)
{
	// std::cout << "(in const max)";
	return a > b ? a : b;
}


//********** Stream **********//
std::ostream	&operator<<(std::ostream & stream, Fixed const & fixed)
{
	stream << fixed.toFloat();
	return stream;
}