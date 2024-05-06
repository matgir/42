#include "Span.hpp"

Span::Span(unsigned int size) : _size(size)
{
	this->_fillAt = 0;
	return;
}

Span::~Span(void)
{
	return;
}

unsigned int	Span::getSize(void)const
{
	return this->_size;
}

void			Span::addNumber(int newNumber)
{
	if (this->_fillAt == this->_size)
	{
		// throw std::out_of_range("Your Span is full !");
		// return;
	}
	this->_span.push_back(newNumber);
	this->_fillAt += 1;
	return;
}

unsigned int	Span::shortestSpan(void)
{
	if (this->_size <= 1 || this->_fillAt <= 1)
	{
		// throw std::length_error("Your Span is too small to call this function !");
		// return 0;
	}
	std::list<int>	copy = this->_span;
	copy.sort();

	std::list<int>::const_iterator	it = copy.begin();
	std::list<int>::const_iterator	ite = copy.end();

	unsigned int	distance = difference(*it, *it + 1);
	unsigned int	tmp;
	it++;
	it++;
	for (it; it != ite; it++)
	{
		tmp = difference(*it - 1, *it);
		if (tmp < distance)
			distance = tmp;
		if (distance == 0)
			return distance;
	}
	return distance;
}

unsigned int	Span::longestSpan(void)
{
	if (this->_size <= 1 || this->_fillAt <= 1)
	{
		// throw std::length_error("Your Span is too small to call this function !");
		// return 0;
	}
	std::list<int>	copy = this->_span;
	copy.sort();
	int	small = *copy.begin();
	copy.reverse();
	int	big = *copy.begin();
	return (difference(small, big));
}

void			Span::fillSpan(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	for (std::list<int>::iterator it = begin; it != end; it++)
	{
		if (this->_span.size() == this->_size)
		{
			// throw std::out_of_range("Your Span is full !");
			// return;
		}
		this->_span.push_back(*it);
		this->_fillAt++;
	}
	return;
}

std::list<int>	Span::getSpan(void)const
{
	return this->_span;
}

unsigned int	difference(int a, int b)
{
	if (a == b)
		return 0;
	else if (a > b)
		return a - b;
	else
		return b - a;
}