#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>
# include "Weapon.h"

class Weapon
{

	private:

		std::string	_type;
	
	public:

		Weapon(std::string type); //_type becomes type
		~Weapon();

		std::string const &	getType(); //return const ref on _type
		void				setType(std::string newtype); // _type becomes newtype

};

#endif