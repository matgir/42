#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:

		WrongAnimal(void);
		WrongAnimal(WrongAnimal const & copy);
		virtual ~WrongAnimal(void);

		WrongAnimal		&operator=(WrongAnimal const & assign);

		std::string		getType(void)const;
		void			makeSound(void);

	protected:

		std::string		_type;
};

#endif