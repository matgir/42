#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

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

		ClapTrap		&operator=(ClapTrap const & copy);

		std::string		getName(void)const;
		unsigned int	getHitPoints(void)const;
		unsigned int	getEnergyPoints(void)const;
		unsigned int	getAttackDamage(void)const;
		void			attack(const std::string & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	protected:

		std::string		_name;
		unsigned int	_hitPoints; //health of the ClapTrap
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;//attack power on _hitpoints
};

#endif
