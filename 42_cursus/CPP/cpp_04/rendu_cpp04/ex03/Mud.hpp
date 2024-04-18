#ifndef MUD_HPP
# define MUD_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Mud : public AMateria
{
	public:

		Mud(void);
		Mud(Mud const & copy);
		~Mud(void);

		Mud	&operator=(Mud const & assign);
		
		AMateria	*clone()const;
		void		use(ICharacter & target);
};

#endif
