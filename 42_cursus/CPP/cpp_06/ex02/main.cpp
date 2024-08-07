// #include "Identify.h"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <ctime>

Base *	generate(void)
{
	Base *		baseClass;

	if (std::time(NULL) % 3 == 0)
		baseClass = new A;
	else if (std::time(NULL) % 2 == 0)
		baseClass = new B;
	else
		baseClass = new C;

	return baseClass;
}

void	identify(Base * p)
{
	std::cout << "pointer identify" << std::endl;

	if (dynamic_cast<A *>(p))
		std::cout << "Base type is : A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Base type is : B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Base type is : C" << std::endl;
	else
		std::cout << "Could not identify the Base type !" << std::endl;
}

void	identify(Base & p)
{
	std::cout << "reference identify" << std::endl;

	try
	{
		dynamic_cast<A &>(p);
		std::cout << "Base type is : A" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "Base type is : B" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "Base type is : C" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	Base *	testBase1;

	testBase1 = generate();

	Base &	testBase2 = *testBase1;

	identify(testBase1);
	identify(testBase2);

	delete testBase1;

	return 0;
}