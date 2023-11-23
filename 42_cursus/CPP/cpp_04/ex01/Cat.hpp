#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:

		Cat(void);
		Cat(Cat const & copy);
		~Cat(void);

		Cat	&operator=(Cat const & assign);

		void	makeSound(void);
		Brain	*getBrain(void)const;

	private:

		Brain*	_catBrain;
};

#endif
