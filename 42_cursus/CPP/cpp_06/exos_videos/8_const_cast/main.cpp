int	main(void)
{
	int			a = 42;						// Reference value

	int const *	b = &a;						// Implicit promotion	-> Ok
	int *		c = b;						// Implicit demotion	-> Hell no !
	int *		d = const_cast<int *>(b);	// Explicit demotion	-> Ok, I obey

	return 0;
}