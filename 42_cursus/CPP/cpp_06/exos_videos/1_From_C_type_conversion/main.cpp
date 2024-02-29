void	dump_32bits_integer(int const n);
void	dump_64bits_integer(double const z);

/*************************************************/

int	main(void)
{
	int		a = 42;				//Reference value

	double	b = a;				//Implicit conversion cast
	double	c = (double)a;		//Explicit conversion cast

	double	d = a;				//Implicit promotion	--> Ok
	int		e = d;				//Implicit demotion		--> Hazardous
	int		f = (int)d;			//Explicit demotion		--> Ok you're in charge

	dump_32bits_integer(a);

	dump_64bits_integer(b);
	dump_64bits_integer(c);

	dump_64bits_integer(d);
	dump_32bits_integer(e);
	dump_32bits_integer(f);
}