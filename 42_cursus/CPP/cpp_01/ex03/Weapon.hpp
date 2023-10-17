#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
#include <iostream>

class Weapon
{
private:
	std::string	type;
public:
	Weapon(void);
	~Weapon();
	std::string&	getType();
	void			setType(std::string newtype);
};

Weapon::Weapon(void)
{
}

Weapon::~Weapon()
{
}


#endif