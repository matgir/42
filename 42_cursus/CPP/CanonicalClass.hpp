// replace canonical by your class name
// replace variable by your variable name

#ifndef CANONICALCLASS_HPP
# define CANONICALCLASS_HPP

# include <iostream>

class Canonical
{
	public:

		Canonical(void);
		Canonical(Canonical const & src);
		~Canonical(void);

		Canonical	&operator=(Canonical const & rhs);

		int		getvariable(void)const;

	private:

		int		_variable;
};

#endif

Canonical::Canonical(void) : _variable(0)
{
	std::cout <<"Default constructor called" << std::endl;
	return;
}

Canonical::Canonical(Canonical const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Canonical::~Canonical(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Canonical::getvariable(void)const
{
	return this->_variable;
}

Canonical	&Canonical::operator=(Canonical const & rhs)
{
	std::cout << "Assigment operator called" << std::endl;

	if (this != &rhs)
		this->_variable = rhs.getvariable();

	return *this;
}