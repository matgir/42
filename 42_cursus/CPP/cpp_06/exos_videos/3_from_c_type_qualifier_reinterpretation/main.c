int	main(void)
{
	int			a = 42;					/* reference value */

	int const *	b = &a;					/* Implicit type qualifier cast */
	int const * c = (int const *) &a;	/* Explicit type qualifier cast */

	int const * d = &a;					/* Implicit promotion	-> Ok*/
	int *		e = d;					/* Implicit demotion	-> Hell no !!*/
	int *		f = (int *) d;			/* Explicit demotion	-> ok, i obey*/

	return 0;
}