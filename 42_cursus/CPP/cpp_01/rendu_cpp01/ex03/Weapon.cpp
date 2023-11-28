#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	return;
}

Weapon::~Weapon()
{
	return;
}

std::string const &	Weapon::getType()
{
	return this->_type;
}

void	Weapon::setType(std::string newtype)
{
	this->_type = newtype;
	return;
}