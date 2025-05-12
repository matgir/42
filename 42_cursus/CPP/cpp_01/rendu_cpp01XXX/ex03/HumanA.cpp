#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	return;
}

HumanA::~HumanA()
{
	return;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return;
}

void	HumanA::getname()
{
	std::cout << "Hello my name is " << this->_name << std::endl;
	return;
}