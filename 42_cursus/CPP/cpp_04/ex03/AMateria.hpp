#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

// # include "AMateria.hpp"
// # include "Character.hpp"
// # include "Cure.hpp"
// # include "Ice.hpp"
# include "ICharacter.hpp"
// # include "IMateriaSource.hpp"
// # include "MateriaSource.hpp"

class ICharacter;
// class IMateriaSource;

class AMateria
{
	public:

		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & copy);
		
		virtual ~AMateria(void);

		AMateria	&operator=(AMateria const & assign);
		// AMateria	&operator=(AMateria const & assign);

		std::string			const & getType()const; //Return materia type
		
		virtual AMateria	*clone()const = 0;
		virtual void		use(ICharacter & target);

	protected:

		std::string	_type;
};

#endif
