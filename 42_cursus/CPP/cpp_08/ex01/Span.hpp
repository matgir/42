// replace canonical by your class unsigned int
// replace getSize(void)const par nouveau getteur
// replace variable by your variable name

#ifndef SPAN_CLASS
# define SPAN_CLASS

# include <iostream>

class Span
{
	public:

		Span(unsigned int size);
		virtual ~Span(void);

		unsigned int	getSize(void)const;
		void			addNumber(int newNumber);//

	private:

		Span(void);
		Span(Span const & copy);
		Span	&operator=(Span const & assign);

		unsigned int			_size;
		unsigned int			_fillAt;
		std::array<int, _size>	_array;
};

#endif

#include "Span.hpp"

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