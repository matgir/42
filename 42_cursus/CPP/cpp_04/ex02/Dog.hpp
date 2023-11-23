#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:

		Dog(void);
		Dog(Dog const & copy);
		~Dog(void);

		Dog	&operator=(Dog const & copy);

		void	makeSound(void);
		Brain	*getBrain(void)const;

	private:

		Brain	*_dogBrain;
};

#endif
