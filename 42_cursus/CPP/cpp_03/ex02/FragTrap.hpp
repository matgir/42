#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & copy);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const & copy);

		void		highFiveGuys(void);
};

#endif