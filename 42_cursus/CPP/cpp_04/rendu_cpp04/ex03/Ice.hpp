#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:

		Ice(void);
		Ice(Ice const & copy);
		~Ice(void);

		Ice	&operator=(Ice const & assign);
		
		AMateria	*clone()const;
		void		use(ICharacter & target);
};

#endif
