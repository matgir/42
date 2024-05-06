// replace canonical by your class unsigned int
// replace getSize(void)const par nouveau getteur
// replace variable by your variable name

#ifndef SPAN_CLASS
# define SPAN_CLASS

# include <iostream>
# include <forward_list>
# include <stdexcept>

class Span
{
	public:

		Span(unsigned int size);
		virtual ~Span(void);

		unsigned int	getSize(void)const;
		void			addNumber(int newNumber);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void)const;

	private:

		Span(void);
		Span(Span const & copy);
		Span	&operator=(Span const & assign);

		unsigned int			_size;
		unsigned int			_fillAt;
		std::forward_list<int>	_span;
};

#endif

// #include "Span.hpp"

Span::Span(unsigned int size) : _size(size)
{
	this->_fillAt = 0;
	return;
}

Span::Span(void)
{
	return;
}

Span::Span(Span const & copy)
{
	return;
}

Span::~Span(void)
{
	std::cout << "Span destructor called" << std::endl;
	return;
}

Span	&Span::operator=(Span const & assign)
{
	return *this;
}

unsigned int	Span::getSize(void)const
{
	return this->_size;
}

void			Span::addNumber(int newNumber)
{
	if (this->_fillAt == this->_size)
	{
		throw std::out_of_range("Your Span is full !");
		return;
	}
	this->_span.push_front(newNumber);
	this->_fillAt += 1;
	return;
}

unsigned int	Span::shortestSpan(void)
{
	unsigned int	distance;

	if (this->_size <= 1 || this->_fillAt <= 1)
	{
		throw std::length_error("Your Span is too small to call this function !");
		return;
	}
	this->_span.sort();
	
}