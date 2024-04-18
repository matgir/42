#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :
	ScavTrap("Default_name_clap_name"),
	FragTrap("Default_name_clap_name")
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->_name = "Default name";
	return;
}

DiamondTrap::DiamondTrap(std::string name) :
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name")
{
	std::cout << "Naming DiamondTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->_name = name;
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy) :
	ScavTrap(copy.getName() + "_clap_name"),
	FragTrap(copy.getName() + "_clap_name")
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	return;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
	return;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const & assign)
{
	std::cout << "DiamondTrap assign operator called" << std::endl;
	if (this != &assign)
	{
		this->_name = assign.getName();
		this->_hitPoints = assign.getHitPoints();
		this->_energyPoints = assign.getEnergyPoints();
		this->_attackDamage = assign.getAttackDamage();
	}
	return *this;
}

std::string	DiamondTrap::getName(void)const
{
	return this->_name;
}

void		DiamondTrap::attack(const std::string & target)
{
	ScavTrap::attack(target);
	return;
}

void		DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap : " << this->getName() << ", but also ClapTrap : ";
	std::cout << ClapTrap::getName() << std::endl;
}
