#include <iostream>

template<Typename T>
class	Array
{
	public:
		Array<T>(void);
		/* Construction with no parameter: Creates an empty array. */
		Array<T>(unsigned int i);
		/* Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
Tip: Try to compile int * a = new int(); then display *a. */
		Array<T>(Array const & copy);
		/* Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array. */

		&operator=(Array const & assign);
		/* Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array. */
		&operator[](void);
		/* When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown. */

		unsigned int	size(void)const;
		/* A member function size() that returns the number of elements in the array. This
member function takes no parameter and musn’t modify the current instance. */
}