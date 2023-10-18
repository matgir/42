#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(0)
{
	return;
}

HumanB::~HumanB()
{
	return;
}

void	HumanB::setWeapon(Weapon& newWeapon)
{
	this->_weapon = &newWeapon;
	return;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return;
}

void	HumanB::getname()
{
	std::cout << "Hello my name is " << this->_name << std::endl;
	return;
}