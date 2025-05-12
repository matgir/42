#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:

		AAnimal(void);
		AAnimal(AAnimal const & copy);
		virtual ~AAnimal(void);

		AAnimal	&operator=(AAnimal const & assign);

		std::string		getType(void)const;
		virtual void	makeSound(void) = 0;

	protected:

		std::string	_type;
};

#endif
