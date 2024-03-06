#include <iostream>
#include <typeinfo>
#include <exception>

class	Parent	{public: virtual ~Parent(void) {} };
class	Child1: public Parent	{};
class	Child2: public Parent	{};

int	main(void)
{
	Child1		a;			// Reference value
	Parent *	b = &a;		// Implicit upcast	-> Ok

	// Explicit downcast	-> Suspens...
	Child1 *	c = dynamic_cast<Child1 *>(b); //ok
	// Child2 *	c = dynamic_cast<Child2 *>(b); //not ok
	if (c == NULL)
		std::cout << "Conversion is NOT OK" << std::endl;
	else
		std::cout << "Conversion is OK" << std::endl;

	// Explicit downcast -> Suspens
	try
	{
		// Child2 &	d = dynamic_cast<Child2 &>(*b); //not ok
		Child1 &	d = dynamic_cast<Child1 &>(*b); //ok
		std::cout << "Conversion is OK" << std::endl;
	}
	catch (std::bad_cast &bc) /*	exception renvoyee si dynamic_cast fail
									en reference*/
	{
		std::cout << "Conversion is NOT OK : " << bc.what() << std::endl;
		return 0;
	}
	return 0;
}