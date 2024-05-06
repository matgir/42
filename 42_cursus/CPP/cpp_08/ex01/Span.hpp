// replace canonical by your class unsigned int
// replace getSize(void)const par nouveau getteur
// replace variable by your variable name

#ifndef SPAN_CLASS
# define SPAN_CLASS

# include <iostream>
# include <forward_list>
# include <stdexcept>
# include "Span.h"

class Span
{
	public:

		Span(unsigned int size);
		virtual ~Span(void);

		unsigned int	getSize(void)const;
		void			addNumber(int newNumber);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			fillSpan(std::forward_list<int>::iterator begin, std::forward_list<int>::iterator end);

	private:

		Span(void);
		Span(Span const & copy);
		Span	&operator=(Span const & assign);

		unsigned int			_size;
		unsigned int			_fillAt;
		std::forward_list<int>	_span;
};

#endif
