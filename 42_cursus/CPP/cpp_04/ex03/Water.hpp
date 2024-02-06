#ifndef WATER_HPP
# define WATER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Water : public AMateria
{
	public:

		Water(void);
		Water(Water const & copy);
		~Water(void);

		Water	&operator=(Water const & assign);

		AMateria	*clone()const;
		void		use(ICharacter & target);
};

#endif
