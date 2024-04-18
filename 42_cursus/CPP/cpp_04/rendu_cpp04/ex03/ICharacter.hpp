#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

// # include <iostream>
# include <string>
# include "AMateria.hpp"
// # include "Character.hpp"
// # include "Cure.hpp"
// # include "Ice.hpp"
// # include "ICharacter.hpp"
// # include "IMateriaSource.hpp"
// # include "MateriaSource.hpp"

class AMateria;

class ICharacter
{
	public:

		virtual						~ICharacter(void) {}
		virtual std::string const &	getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter & target) = 0;
};

#endif
