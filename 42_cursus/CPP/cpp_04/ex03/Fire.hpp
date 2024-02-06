#ifndef FIRE_HPP
# define FIRE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Fire : public AMateria
{
	public:

		Fire(void);
		Fire(Fire const & copy);
		~Fire(void);

		Fire	&operator=(Fire const & assign);

		AMateria	*clone()const;
		void		use(ICharacter & target);
};

#endif
