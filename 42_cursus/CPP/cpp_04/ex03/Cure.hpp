#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:

		Cure(void);
		// Cure(std::string const & type);//a retirer pour Cure et cure
		Cure(Cure const & copy);
		~Cure(void);

		Cure	&operator=(Cure const & assign); // a modifier pour Cure et cure

		// std::string			const & getType()const;	//Return materia type
													//a retirer pour Cure et Cure
		
		Cure	*clone()const; //a creer pour Cure et cure
		void	use(ICharacter & target); // a refaire pour Cure et cure

	protected:

		// std::string	_type; //retirer pour Cure et cure mais bien set leur type a creation

	private:

};

#endif

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Default constructor called" << std::endl;
	this->_type = "cure";
	return;
}

/* Cure::Cure(std::string const & type)
{
	std::cout << "Typing constructor called" << std::endl;
	this->_type = type;
	return;
} */

Cure::Cure(Cure const & copy) : AMateria(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	// this->_type = copy.getType(); // pas sur si oui ou non
	return;
}

Cure::~Cure(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Cure	&Cure::operator=(Cure const & assign)
{
	std::cout << "Assignment operator called" << std::endl;

	// if (this != &assign)
		// this->_type = assign.getType();

	return *this;
}

/* std::string	const & Cure::getType()const
{
	return this->_type;
} */

void		Cure::use(ICharacter & target)
{
	/*	#### something that truly hurt de Icharacter, maybe the use of function
		getHurt()  in ICharacter */
	std::cout << "'* heals " << target.getName() << "'s wounds *'"; // change for Cure
	std::cout << std::endl;
}

Cure		*Cure::clone()const
{
	Cure	*newCure = new Cure();
	return newCure;
}