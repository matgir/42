// replace canonical by your class name
// replace variable by your variable name

#ifndef CANONICALCLASS_HPP
# define CANONICALCLASS_HPP

# include <iostream>

class Canonical
{
	public:

		Canonical(void);
		Canonical(Canonical const & copy);
		virtual ~Canonical(void);

		Canonical	&operator=(Canonical const & assign);

		int		getvariable(void)const;//

	private:

		int		_variable;//
};

#endif

Canonical::Canonical(void) : _variable(0)
{
	std::cout << "Cannocical default constructor called" << std::endl;
	return;
}

Canonical::Canonical(Canonical const & copy)
{
	std::cout << "Cannocical copy constructor called" << std::endl;
	this->_variable = copy.getvariable();
	return;
}

Canonical::~Canonical(void)
{
	std::cout << "Cannocical destructor called" << std::endl;
	return;
}

int	Canonical::getvariable(void)const
{
	return this->_variable;
}

Canonical	&Canonical::operator=(Canonical const & assign)
{
	std::cout << "Cannocical assignment operator called" << std::endl;

	if (this != &assign)
		this->_variable = assign.getvariable();

	return *this;
}