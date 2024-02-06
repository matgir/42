#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	public:

		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & copy);
		virtual ~AMateria(void);

		AMateria	&operator=(AMateria const & assign);

		std::string			const & getType()const; //Return materia type
		
		virtual AMateria	*clone()const = 0;
		virtual void		use(ICharacter & target);

	protected:

		std::string	_type;

	private:

};

#endif

AMateria::AMateria(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_type = "Default type";
	return;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "Typing constructor called" << std::endl;
	this->_type = type;
	return;
}

AMateria::AMateria(AMateria const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_type = copy.getType();
	return;
}

AMateria::~AMateria(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

AMateria	&AMateria::operator=(AMateria const & assign)
{
	std::cout << "assignment operator called" << std::endl;

	if (this != &assign)
		this->_type = assign.getType();

	return *this;
}

std::string	const & AMateria::getType()const
{
	return this->_type;
}

void		AMateria::use(ICharacter & target)
{
	/* ####### */
}
