#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{

	private:

		std::string	_name;
		Weapon&		_weapon;

	public:

		HumanA(std::string name, Weapon& weapon); //_name/_weapon becomes name/weapon
		~HumanA();

		void	attack(); // print "<name> attacks with their <weapon type>"
		void	getname(); // tell the name of the human
};

#endif