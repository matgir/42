#include "IntegerClass.hpp"

IntegerClass::IntegerClass(int const n): _n(n)
{
	std::cout << "Constructor called with value " << n << std::endl;
	return;
}

IntegerClass::~IntegerClass()
{
	std::cout << "Destructor called with value " << this->_n << std::endl;\
	return;
}

int	IntegerClass::getvalue(void)const
{
	return this->_n;
}

IntegerClass	&IntegerClass::operator=(IntegerClass const & rhs)
{
	std::cout << "Assignation operator called from " << this->_n;
	std::cout << " to " << rhs.getvalue() << std::endl;

	this->_n = rhs.getvalue();

	return *this;
}

IntegerClass	IntegerClass::operator+(IntegerClass const & rhs) const
{
	std::cout << "Addition operator called with " << this->_n;
	std::cout << " and " << rhs.getvalue() << std::endl;

	return IntegerClass(this->_n + rhs.getvalue());
}

std::ostream	&operator<<(std::ostream & o, IntegerClass const & rhs)
{
	o << rhs.getvalue();
	return o;
}