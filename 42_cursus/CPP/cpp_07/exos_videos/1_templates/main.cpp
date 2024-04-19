#include <iostream>

// int	max(int x, int y)
// {
	// return (x >= y ? x : y);
// }

template< typename T >				//Template definition

/*	-	recuperer par adresse & au cas ou les variables sont tres lourdes (class)
	donc on va eviter de les copier dans notre fonction
	-	const car on ne va rien modifier
	*/

T const &	max(T const & x, T const & y)
{
	return (y >= x ? y : x);
}

int	foo(int x)
{
	std::cout << "long computing time" << std::endl;
	return x;
}

int	main(void)
{
	int	a = 21;
	int	b = 22;

	std::cout << "Max of " << a << " and " << b << " is ";
	if (&max<int>(a, b) == &b)
		std::cout << max<int>(a ,b) << std::endl;		//explicit instanciation
	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << max(a ,b) << std::endl;			//implicit instanciation

	float	c = -1.7f;
	float	d = 4.2f;

	std::cout << "Max of " << c << " and " << d << " is ";
	std::cout << max<float>(c ,d) << std::endl;		//explicit instanciation
	std::cout << "Max of " << c << " and " << d << " is ";
	std::cout << max(c ,d) << std::endl;			//implicit instanciation

	char	e = 'a';
	char	f = 'z';

	std::cout << "Max of " << e << " and " << f << " is ";
	std::cout << max<char>(e ,f) << std::endl;		//explicit instanciation
	std::cout << "Max of " << e << " and " << f << " is ";
	std::cout << max(e ,f) << std::endl;			//implicit instanciation

	//No problem here
	int	ret = max<int>(foo(a), foo(b));				//explicit instanciation
	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << ret << std::endl;

	return 0;
}