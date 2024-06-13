#include "Span.hpp"

Span::Span(void) : _size(0)
{
	this->_fillAt = 0;
	return;
}

Span::Span(unsigned int size) : _size(size)
{
	this->_fillAt = 0;
	return;
}

Span::Span(Span const & copy)
{
	this->_size = copy.getSize();
	this->_fillAt = copy.getFillAt();
	this->_span.clear();
	this->_span.insert(this->_span.end(), (copy.getSpan()).begin(), (copy.getSpan()).end());
	return;
}

Span	&Span::operator=(Span const & assign)
{
	if (this != &assign)
	{
		this->_size = assign.getSize();
		this->_fillAt = assign.getFillAt();
		this->_span.clear();
		this->_span.insert(this->_span.end(), (assign.getSpan()).begin(), (assign.getSpan()).end());
	}
	return *this;
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
		throw Span::SpanIsFull();
		return;
	}
	this->_span.push_back(newNumber);
	this->_fillAt += 1;
	return;
}

unsigned int	Span::shortestSpan(void)
{
	if (this->_size <= 1 || this->_fillAt <= 1)
	{
		throw Span::SpanIsTooShort();
		return 0;
	}
	std::list<int>	copy = std::list<int>(this->_span);
	copy.sort();

	std::list<int>::const_iterator	it = copy.begin();
	std::list<int>::const_iterator	ite = copy.end();

	unsigned int	intTmp = *it;
	it++;
	unsigned int	distance = difference(*it, intTmp);
	intTmp = *it;
	it++;
	for (it; it != ite; it++)
	{
		unsigned int	distTmp = distance;
		distance = difference(*it, intTmp);
		if (distTmp < distance)
			distance = distTmp;
		if (distance == 0)
			return distance;
		intTmp = *it;
	}
	return distance;
}

unsigned int	Span::longestSpan(void)
{
	if (this->_size <= 1 || this->_fillAt <= 1)
	{
		throw Span::SpanIsTooShort();
		return 0;
	}
	std::list<int>	copy = std::list<int>(this->_span);
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
			throw Span::SpanIsFull();
			return;
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

unsigned int	Span::getFillAt(void)const
{
	return this->_fillAt;
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