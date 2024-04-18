#include "Point.hpp"

Point::Point(void)
{
	this->_x = (Fixed(0));
	this->_y = (Fixed(0));
	return;
}

Point::Point(const float x, const float y)
{
	this->_x = (Fixed(x));
	this->_y = (Fixed(y));
	return;
}

Point::Point(Point const & copy)
{
	this->_x = copy.getX();
	this->_y = copy.getY();
	return;
}

Point::~Point(void)
{
	return;
}

Fixed	Point::getX(void)const
{
	return this->_x;
}

Fixed	Point::getY(void)const
{
	return this->_y;
}

Point	&Point::operator=(Point const & assign)
{
	if (this != &assign)
	{
		this->_x = assign.getX();
		this->_y = assign.getY();
	}
	return *this;
}