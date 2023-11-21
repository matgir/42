#include "ClaptrapClass.hpp"

ClapTrap::ClapTrap(void) : _name("Default_name")
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackPoints = 0;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "Name ClapTrap constructor called" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackPoints = 0;
	return;
}


ClapTrap::ClapTrap(ClapTrap const & copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const & copy)
{
	std::cout << "ClapTrap assigment operator called" << std::endl;

	if (this != &copy)
	{
		this->_name = copy.getName();
		this->_hitPoints = copy.getHitPoints();
		this->_energyPoints = copy.getEnergyPoints();
		this->_attackPoints = copy.getAttackPoints();
	}
	return *this;
}

std::string	ClapTrap::getName(void)const
{
	return this->_name;
}

unsigned int	ClapTrap::getHitPoints(void)const
{
	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(void)const
{
	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackPoints(void)const
{
	return this->_attackPoints;
}

void			ClapTrap::attack(const std::string & target)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " cannot attack because it has 0 Hit points !" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " cannot attack because it has 0 Energy Points !" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_hitPoints << " points of damage!" << std::endl;
	}
	return;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage. It has now " << this->_hitPoints << " Hit points !" << std::endl;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " cannot attack because it has 0 Hit points !" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " cannot attack because it has 0 Energy Points !" << std::endl;
	else
	{
		this->_energyPoints--;
		if (amount > UINT_MAX - this->_hitPoints)
			this->_hitPoints = UINT_MAX;
		else
			this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " regain " << amount << " Hit points. It has now " << this->_hitPoints << " Hit point !" << std::endl;
	}
}