#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
// # include "Character.hpp"
// # include "Cure.hpp"
// # include "Ice.hpp"
# include "ICharacter.hpp"
// # include "IMateriaSource.hpp"
// # include "MateriaSource.hpp"

// class ICharacter;
// class AMateria;

class Character : public ICharacter
{
	public:

		Character(void);
		Character(std::string name);
		Character(Character const & copy);
		~Character(void);

		// Character	&operator=(Character const & assign)
		Character	&operator=(Character const & assign);

		virtual AMateria			*getMateria(int idx)const;
		virtual std::string const &	getName() const;
		virtual void				equip(AMateria * m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter & target);

	private:

		AMateria	*_materias[4];
		std::string	_name;
};

#endif
