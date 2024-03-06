#include <stdio.h>

int	main(void)
{
	float	a = 420.042f;		//Reference value

	void *	b = &a;				//Implicit reinterpretation cast
	void *	c = (void *)&a;		//Explicit reinterpretation cast

	void *	d = &a;				//Implicit promotion	--> Ok
	int *	e = d;				//Implicit demotion		--> Hazardous !
	int *	f = (int *)d;		//Explicit demotion		--> Ok I obey

	printf("%p, %f\n", &a, a);

	printf("%p\n", b),
	printf("%p\n", c);

	printf("%p\n", d);
	printf("%p, %d\n", e, *e);
	printf("%p, %d\n", f, *f);

	return 0;
}