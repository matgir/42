#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

// # include <iostream>
# include "AMateria.hpp"
// # include "Character.hpp"
// # include "Cure.hpp"
// # include "Ice.hpp"
// # include "ICharacter.hpp"
// # include "IMateriaSource.hpp"
// # include "MateriaSource.hpp"

// class AMateria;

class IMateriaSource
{
	public:

		virtual				~IMateriaSource(void) {}
		virtual void		learnMateria(AMateria* m) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif
