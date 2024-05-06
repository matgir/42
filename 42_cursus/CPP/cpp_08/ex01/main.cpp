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
			span->addNumber(23);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			span->addNumber(56);
			span->longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			span->addNumber(89);
			span->shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete span;
	}
	std::cout << std::endl << std::endl;
	{
		Span *	span = new Span(15000);
		
		srand(time(NULL));
		for (int i = 0; i > -15000; i--)
			span->addNumber(rand() * i);
		std::cout << span->longestSpan() << std::endl;
		std::cout << span->shortestSpan() << std::endl;

		Span *	copy = new Span(15002);

		copy->fillSpan((span->getSpan()).begin(), (span->getSpan()).end());
		std::cout << copy->longestSpan() << std::endl;
		std::cout << copy->shortestSpan() << std::endl;
		delete span;
		delete copy;
	}
	return 0;
}