#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : virtual public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & copy);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const & assign);

		void		highFiveGuys(void);
};

#endif