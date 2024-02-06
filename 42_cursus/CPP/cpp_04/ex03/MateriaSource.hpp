#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

// # include <iostream>
# include "AMateria.hpp"
// # include "Character.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
// # include "ICharacter.hpp"
# include "IMateriaSource.hpp"
// # include "MateriaSource.hpp"

// class IMateriaSource;
// class AMateria;

class MateriaSoucre : public IMateriaSource
{
	public:

		MateriaSoucre(void);
		MateriaSoucre(MateriaSoucre const & copy);
		~MateriaSoucre(void);

		MateriaSoucre	&operator=(MateriaSoucre const & assign);

		virtual AMateria	*getMateria(int idx)const;
		virtual void		learnMateria(AMateria * m);
		virtual AMateria *	createMateria(std::string const & type);

	private:

		AMateria	*_learnedMaterias[4];
};

#endif
