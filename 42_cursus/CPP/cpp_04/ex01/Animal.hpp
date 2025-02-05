#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	public:

		Animal(void);
		Animal(Animal const & copy);
		virtual ~Animal(void);

		Animal	&operator=(Animal const & assign);

		std::string		getType(void)const;
		virtual void	makeSound(void);

	protected:

		std::string	_type;
};

#endif
