#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & copy);
		~ScavTrap(void);
		
		ScavTrap	&operator=(ScavTrap const & assign);

		void	attack(const std::string & target);
		void	guardGate(void);

};

#endif