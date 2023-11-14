#ifndef INTEGERCLASS_HPP
# define INTEGERCLASS_HPP

# include <iostream>

class IntegerClass
{
	private:

		int	_n;

	public:

		IntegerClass(int const n);
		~IntegerClass(void);

		int	getvalue(void)const;

		IntegerClass	&operator=(IntegerClass const & rhs);
		IntegerClass	operator+(IntegerClass const & rhs) const;
};

std::ostream	&operator<<(std::ostream & o, IntegerClass const & rhs);

#endif