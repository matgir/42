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

		// Character	&operator=(Character const & assign)
		Character	&operator=(Character const & assign);

		AMateria	*getMateria(int idx)const;
		std::string const &	getName() const;
		void		equip(AMateria * m);
		void		unequip(int idx);
		void		use(int idx, ICharacter & target);

	private:

		AMateria	*_materias[4];
		std::string	_name;
};

#endif

Character::Character(void)
{
	std::cout <<"Default constructor called" << std::endl;
	this->_name = "Default character name";
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	return;
}

Character::Character(std::string name)
{
	std::cout << "Naming constructor called" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	return;
}

Character::Character(Character const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_name = copy.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
		this->_materias[i] = new AMateria(copy.getMateria(i));
	}
	return;
}

Character::~Character(void)
{
	std::cout << "Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_materias[i])
			delete this->_materias[i];
	return;
}

Character			&Character::operator=(Character const & assign)
{
	std::cout << "Assignment operator called" << std::endl;

	if (this != &assign)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
				delete this->_materias[i];
			this->_materias[i] = new AMateria(assign.getMateria(i));
		}
	}
	return *this;
}

AMateria			*Character::getMateria(int idx)const
{
	if (this->_materias[idx])
		return this->_materias[idx];
	else
	{
		std::cout << "There is no Materia at slot " << idx << " !" << std::endl;
		return NULL;
	}
}

std::string const &	Character::getName() const
{
	return this->_name;
}

void				Character::equip(AMateria * m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materias[i])
			this->_materias[i] = m;
		else
			std::cout << "Invetory is full, use <unequip> first !" << std::endl;
	}
	return;
}

void				Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "Wrong inventory index, must be between 0 and 3 !" << std::endl;
	else if (!this->_materias[idx])
		std::cout << "The inventory " << idx << " is empty !" << std::endl;
	else
	{
		if (this->_materias[idx])
		{
			std::cout << "Materia " << this->_materias[idx]->getType() << " at index ";
			std::cout << idx << " has been unequiped !" << std::endl;
			// delete this->_materias[idx];//doit pas delete, trouver autre moyen
		}
		this->_materias[idx] = new AMateria();
	}
	return;
}

void				Character::use(int idx, ICharacter & target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Wrong inventory index, must be between 0 and 3 !" << std::endl;
	else if (!this->_materias[idx])
		std::cout << "The inventory " << idx << " is empty !" << std::endl;
	else
		this->_materias[idx]->use(target);
	return;
}
