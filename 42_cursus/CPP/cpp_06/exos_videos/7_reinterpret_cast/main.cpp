int	main(void)
{
	float	a = 420.042f;					// Reference value

	void *	b = &a;							// Implicit promotion	-> Ok
	int *	c = reinterpret_cast<int *>(b);	// Explicit demotion	-> Ok, I obey
	int &	d = reinterpret_cast<int &>(b); // Explicit demotion	-> Ok, I obey

	return 0;
}