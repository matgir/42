// replace canonical by your class name
// replace getvariable(void)const par nouveau getteur
// replace variable by your variable name

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>

class BitcoinExchange
{
	public:

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & copy);
		virtual ~BitcoinExchange(void);

		BitcoinExchange	&operator=(BitcoinExchange const & assign);

		int		getvariable(void)const;//

	private:

		int		_variable;//
};

#endif

// #include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _variable(0)
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
	return;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy)
{
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	this->_variable = copy.getvariable();
	return;
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
	return;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const & assign)
{
	std::cout << "BitcoinExchange assignment operator called" << std::endl;

	if (this != &assign)
		this->_variable = assign.getvariable();

	return *this;
}

int	BitcoinExchange::getvariable(void)const
{
	return this->_variable;
}