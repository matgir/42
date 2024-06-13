#ifndef SPAN_CLASS
# define SPAN_CLASS

# include <iostream>
# include <list>
# include <stdexcept>
# include "Span.h"

class Span
{
	public:

		Span(unsigned int size);
		Span(Span const & copy);
		Span	&operator=(Span const & assign);
		virtual ~Span(void);

		unsigned int	getSize(void)const;
		void			addNumber(int newNumber);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			fillSpan(std::list<int>::iterator begin, std::list<int>::iterator end);
		std::list<int>	getSpan(void)const;
		unsigned int	getFillAt(void)const;

		class	SpanIsFull : public std::exception
		{
			public:
				virtual const char *	what() const throw()
				{
					return ("Your Span is full !");
				}
		};

		class	SpanIsTooShort : public std::exception
		{
			public:
				virtual const char *	what() const throw()
				{
					return ("Your Span is too short to call this function");
				}
		};

	private:

		Span(void);
		unsigned int	_size;
		unsigned int	_fillAt;
		std::list<int>	_span;
};

#endif
