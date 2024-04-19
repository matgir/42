#include <stdio.h>

int		max_int(int x, int y)		{return (x >= y ? x : y);}
float	max_float(float x, float y)	{return (x >= y ? x : y);}
char	max_char(char x, char y)	{return (x >= y ? x : y);}

int		foo(int x) {printf("Long computing time\n"); return x;}

#define max(x, y) (((x) >= (y)) ? (x) : (y))

int	main(void)
{
	int	a = 21;
	int	b = 42;

	printf("Max of %d and %d is %d\n", a, b, max_int(a ,b));
	printf("Max of %d and %d is %d\n", a, b, max(a ,b));

	float	c = -1.7f;
	float	d = 4.2f;

	printf("Max of %f and %f is %f\n", c, d, max_float(c ,d));
	printf("Max of %f and %f is %f\n", c, d, max(c ,d));

	char	e = 'a';
	char	f = 'z';

	printf("Max of %c and %c is %c\n", e, f, max_char(e ,f));
	printf("Max of %c and %c is %c\n", e, f, max(e ,f));

	/* But... */
	printf("Max of %d and %d is %d\n", a, b, max_int(foo(a) ,foo(b)));
	printf("Max of %d and %d is %d\n", a, b, max(foo(a) ,foo(b)));
}