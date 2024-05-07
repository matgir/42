#include "Span.hpp"
#include <stdlib.h>
#include <time.h>

int	main(void)
{
	std::cout << std::endl << std::endl;
	{
		Span *	span = new Span(1);
		try
		{
			span->addNumber(56);
			span->longestSpan();
		}
		catch(Span::SpanIsTooShort & e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			span->addNumber(56);
			span->addNumber(23);
		}
		catch(Span::SpanIsFull & e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			span->addNumber(89);
			span->shortestSpan();
		}
		catch(Span::SpanIsTooShort& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete span;
	}
	std::cout << std::endl << std::endl;
	{
		Span *	span = new Span(15000);

		srand(time(NULL));
		for (int i = 7500; i > -7500; i--)
			span->addNumber(rand() * i);
		std::cout << span->longestSpan() << std::endl;
		std::cout << span->shortestSpan() << std::endl;
		std::cout << (span->getSpan().size()) << std::endl;

		Span *	copy = new Span(15000);

		try
		{
			copy->fillSpan((span->getSpan()).begin(), (span->getSpan()).end());
		}
		catch(Span::SpanIsFull & e)
		{
			std::cerr << e.what() << "\n";
		}
		std::cout << copy->longestSpan() << std::endl;
		std::cout << copy->shortestSpan() << std::endl;
		std::cout << (copy->getSpan().size()) << std::endl;

		delete span;
		delete copy;
	}
	std::cout << std::endl << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}
