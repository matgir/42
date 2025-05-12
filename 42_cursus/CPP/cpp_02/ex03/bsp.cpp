#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point& A, const Point& B, const Point& C, const Point& P)
{
	float denominator = ((B.getY()).toFloat() - (C.getY()).toFloat())
			* ((A.getX()).toFloat() - (C.getX()).toFloat())
			+ ((C.getX()).toFloat() - (B.getX()).toFloat())
			* ((A.getY()).toFloat() - (C.getY()).toFloat());

	float u = (((B.getY()).toFloat() - (C.getY()).toFloat())
			* ((P.getX()).toFloat() - (C.getX()).toFloat())
			+ ((C.getX()).toFloat() - (B.getX()).toFloat())
			* ((P.getY()).toFloat() - (C.getY()).toFloat())) / denominator;
	float v = (((C.getY()).toFloat() - (A.getY()).toFloat())
			* ((P.getX()).toFloat() - (C.getX()).toFloat())
			+ ((A.getX()).toFloat() - (C.getX()).toFloat())
			* ((P.getY()).toFloat() - (C.getY()).toFloat())) / denominator;
	float w = 1.0f - u - v;

	return (u >= 0.0f) && (v >= 0.0f) && (w >= 0.0f);
}

