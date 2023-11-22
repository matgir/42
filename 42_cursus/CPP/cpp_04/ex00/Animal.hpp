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

		Animal	&operator=(Animal const & copy);

		std::string		getType(void)const;
		virtual void	makeSound(void)const;

	protected:

		std::string	_type;
};

#endif
