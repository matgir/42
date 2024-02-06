// replace Character by your class name
// replace variable by your variable name

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:

		Character(void);
		Character(std::string name);
		Character(Character const & copy);
		~Character(void);

		Character	&operator=(Character const & assign);

		AMateria	*getMateria(int idx)const;
		std::string const &	getName() const;
		void		equip(AMateria * m);
		void		unequip(int idx);
		void		use(int idx, ICharacter & target);

	private:

		AMateria	_materias[4];
		std::string	_name;
};

#endif

Character::Character(void)
{
	std::cout <<"Default constructor called" << std::endl;
	this->_name = "Default character name";
	this->_materias = new AMateria[4];
	return;
}

Character::Character(Character const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_materias = copy.getMateria();
	return;
}

Character::~Character(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

AMateria	*Character::getMateria(int idx)const
{
	return this->_materias;
}

Character	&Character::operator=(Character const & assign)
{
	std::cout << "assignment operator called" << std::endl;

	if (this != &assign)
		this->_materias = assign.getMateria();

	return *this;
}