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
	Child1 *	e = d;				/* Implicit downcast	-> Hell no ! */
	Child2 *	f = (Child2 *)d;	/* Eplicit downcast		-> Ok, but really ? */
	return 0;
}