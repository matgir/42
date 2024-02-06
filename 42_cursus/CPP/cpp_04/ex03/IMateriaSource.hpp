// replace canonical by your class name
// replace variable by your variable name

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
	public:

		virtual				~IMateriaSource(void) {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria *	createMateria(std::string const & type) = 0;
};

#endif
