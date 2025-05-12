#include <iostream>

class	A {};
class	B {};

class	C
{
	public:
					C(A const & _ )	{return;}
		explicit	C(B const & _ )	{return;} /*	explicit ici permet d'interdire
													la conversion implicit de b vers C*/
};

void	f(C const & _)
{
	return;
}

int	main(void)
{
	f(A());	// Implicit conversion Ok
	f(B());	// Implicit conversio NOT OK, constructor is explicit

	B	b;
	C	c(b);
	f(c);	// Ok because de conversion isn't implicit but explicit as it was done before
	return 0;
}