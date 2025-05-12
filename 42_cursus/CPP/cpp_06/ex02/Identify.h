#ifndef IDENTIFY_H
# define IDENTIFY_H

# include <ctime>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

class	Base;

Base *	generate(void);
void	identify(Base * p);
void	identify(Base & p);

#endif