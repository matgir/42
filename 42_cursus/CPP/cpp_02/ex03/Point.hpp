#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	public:

		Point(void);
		Point(const float x, const float y);
		Point(Point const & copy);
		~Point(void);

		Point	&operator=(Point const & assign);

		Fixed	getX(void)const;
		Fixed	getY(void)const;

	private:

		Fixed	_x;
		Fixed	_y;
};

bool bsp(const Point& A, const Point& B, const Point& C, const Point& P);

#endif
