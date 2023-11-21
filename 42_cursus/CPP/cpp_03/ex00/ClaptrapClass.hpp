// replace canonical by your class name
// replace variable by your variable name

#ifndef CLAPTRAPCLASS_HPP
# define CLAPTRAPCLASS_HPP

# include <iostream>
# include <string>
# include <climits>

class ClapTrap
{
	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & copy);
		~ClapTrap(void);

		ClapTrap	&operator=(ClapTrap const & copy);

		std::string		getName(void)const;
		unsigned int	getHitPoints(void)const;
		unsigned int	getEnergyPoints(void)const;
		unsigned int	getAttackPoints(void)const;
		void			attack(const std::string & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	private:

		std::string		_name;
		unsigned int	_hitPoints; //health of the ClapTrap
		unsigned int	_energyPoints;
		unsigned int	_attackPoints;//attack power on _hitpoints
};

#endif
