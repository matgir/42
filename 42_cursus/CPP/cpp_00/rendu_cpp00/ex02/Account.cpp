#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	int	nbAccount = Account::getNbAccounts();
	int	totalAmount = Account::getTotalAmount();
	int	nbDeposits = Account::getNbDeposits();
	int nbWithdrawals = Account::getNbWithdrawals();

	Account::_displayTimestamp();
	std::cout << " accounts:" << nbAccount << ";total:" << totalAmount;
	std::cout << ";deposits:" << nbDeposits << ";withdrawals:" << nbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount = this->_amount;

	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << p_amount;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount = this->_amount;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << p_amount;
	if (checkAmount() - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int	Account::checkAmount(void)const
{
	return (this->_amount);
}

void	Account::displayStatus(void)const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:";
	std::cout << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	timeStamp = std::time(NULL);
	std::cout << "[" << timeStamp << "]";
	/* ########## faire calucul qui permet dafficher date ########## */
}