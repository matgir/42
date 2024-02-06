#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:

		Ice(void);
		// Ice(std::string const & type);//a retirer pour ice et cure
		Ice(Ice const & copy);
		~Ice(void);

		Ice	&operator=(Ice const & assign); // a modifier pour ice et cure

		// std::string			const & getType()const;	//Return materia type
													//a retirer pour ice et Cure
		
		Ice		*clone()const; //a creer pour ice et cure
		void	use(ICharacter & target); // a refaire pour ice et cure

	protected:

		// std::string	_type; //retirer pour ice et cure mais bien set leur type a creation

	private:

};

#endif

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Default constructor called" << std::endl;
	this->_type = "ice";
	return;
}

/* Ice::Ice(std::string const & type)
{
	std::cout << "Typing constructor called" << std::endl;
	this->_type = type;
	return;
} */

Ice::Ice(Ice const & copy) : AMateria(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	// this->_type = copy.getType(); // pas sur si oui ou non
	return;
}

Ice::~Ice(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Ice	&Ice::operator=(Ice const & assign)
{
	std::cout << "Assignment operator called" << std::endl;

	// if (this != &assign)
		// this->_type = assign.getType();

	return *this;
}

/* std::string	const & Ice::getType()const
{
	return this->_type;
} */

void		Ice::use(ICharacter & target)
{
	/*	#### something that truly hurt de Icharacter, maybe the use of function
		getHurt()  in ICharacter */
	std::cout << "'* shoots an ice bolt at " << target.getName() << " *'"; // change for Cure
	std::cout << std::endl;
}

Ice		*Ice::clone()const
{
	Ice	*newice = new Ice();
	return newice;
}