// replace canonical by your class name
// replace getvariable(void)const par nouveau getteur
// replace variable by your variable name

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <utility>
# include <vector>
# include <stdlib.h>
# include <deque>

std::vector<int>	algoVect(std::vector<int> myVect);
std::deque<int>		algoDeque(std::deque<int> myDeque);

#endif

// class Canonical
// {
// 	public:

// 		Canonical(void);
// 		Canonical(Canonical const & copy);
// 		virtual ~Canonical(void);

// 		Canonical	&operator=(Canonical const & assign);

// 		int		getvariable(void)const;//

// 	private:

// 		int		_variable;//
// };

// #include "Canonical.hpp"

// Canonical::Canonical(void) : _variable(0)
// {
// 	std::cout << "Canonical default constructor called" << std::endl;
// 	return;
// }

// Canonical::Canonical(Canonical const & copy)
// {
// 	std::cout << "Canonical copy constructor called" << std::endl;
// 	this->_variable = copy.getvariable();
// 	return;
// }

// Canonical::~Canonical(void)
// {
// 	std::cout << "Canonical destructor called" << std::endl;
// 	return;
// }

// Canonical	&Canonical::operator=(Canonical const & assign)
// {
// 	std::cout << "Canonical assignment operator called" << std::endl;

// 	if (this != &assign)
// 		this->_variable = assign.getvariable();

// 	return *this;
// }

// int	Canonical::getvariable(void)const
// {
// 	return this->_variable;
// }