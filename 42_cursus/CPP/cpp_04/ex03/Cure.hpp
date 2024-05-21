#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:

		Cure(void);
		Cure(Cure const & copy);
		~Cure(void);

		Cure	&operator=(Cure const & assign);

		AMateria	*clone()const;
		void		use(ICharacter & target);
};

#endif
