#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:

		AAnimal(void);
		AAnimal(AAnimal const & copy);
		virtual ~AAnimal(void) = 0;

		AAnimal	&operator=(AAnimal const & assign);

		std::string		getType(void)const;
		virtual void	makeSound(void);

	protected:

		std::string	_type;
};

#endif
