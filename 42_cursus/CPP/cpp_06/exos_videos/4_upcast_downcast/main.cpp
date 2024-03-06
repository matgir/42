#include <iostream>

class	Parent					{};
class	Child1: public Parent	{};
class	Child2: public Parent	{};

int	main(void)
{
	Child1		a;					/* Reference value */

	Parent *	b = &a;				/* Implicit 'reinterpretation' cast */
	Parent *	c = (Parent *)&a;	/* Explicit 'reinterpretation' cast */

	Parent *	d = &a;				/* Implicit upcast		-> Ok */
	Child1 *	e = d;				/* Implicit downcast	-> Hell no !,
										le compilo l'empeche*/
	Child2 *	f = (Child2 *)d;	/* Explicit downcast	-> Ok, but really ?
										pas ouf au moment de la compil car
										child1 est surement different de child2*/
	return 0;
}