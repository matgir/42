#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"
# include "HumanB.h"

class HumanB
{

	private:
	
		std::string	_name;
		Weapon*		_weapon;
	
	public:
	
		HumanB(std::string name); //_name becomes name
		~HumanB();

		void	setWeapon(Weapon& newweapon); //_weapon becomes newweapon
		void	attack();// print "<name> attacks with their <weapon type>"
		void	getname(); // tell the name of the human

};

#endif