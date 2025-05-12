#include "whatever.hpp"

int	main( void )
{
	int a = 3;
	int b = 65;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	// if (&::min(a, b) == &b)
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	// if (&::min(a, b) != &b)
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	float	e = 1.12345f;
	float	f = -1.12346f;

	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
	std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;

	// ::min(a, c);
	// ::max(a, c);
	// ::swap(a, c);

	return 0;
}
