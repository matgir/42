// replace DiamondTrap by your class name
// replace variable by your variable name

#ifndef DIAMONDTRA_HPP
# define DIAMONDTRA_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:

		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & assign);
		~DiamondTrap(void);

		DiamondTrap	&operator=(DiamondTrap const & copy);
		std::string	getName(void)const;
		void		attack(const std::string & target);
		void		whoAmI();

	private:

		std::string	_name;
};

#endif
