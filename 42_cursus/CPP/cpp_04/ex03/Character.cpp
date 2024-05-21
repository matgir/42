#include "Character.hpp"

Character::Character(void)
{
	// std::cout <<"Character default constructor called" << std::endl;
	this->_name = "Default character name";
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	return;
}

Character::Character(std::string name)
{
	// std::cout << "Character naming constructor called for " << name << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	return;
}

Character::Character(Character const & copy)
{
	// std::cout << "Character copy constructor called" << std::endl;
	this->_name = copy.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
		this->_materias[i] = NULL;
		if (copy.getMateria(i))
			this->_materias[i] = copy.getMateria(i)->clone();
	}
	return;
}

Character::~Character(void)
{
	// std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_materias[i])
			delete this->_materias[i];
	return;
}

Character			&Character::operator=(Character const & assign)
{
	// std::cout << "Character assignment operator called" << std::endl;

	if (this != &assign)
	{
		this->_name = assign.getName();
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
				delete this->_materias[i];
			this->_materias[i] = NULL;
			if (assign.getMateria(i))
				this->_materias[i] = assign.getMateria(i)->clone();
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
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i] && (this->_materias[i]->getType() == m->getType()))
			{
				std::cout << "You already possess " << m->getType() << " in your inventory !";
				std::cout << std::endl;
				return;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (!this->_materias[i])
			{
				this->_materias[i] = m;
				return;
			}
			else if (i == 3)
				std::cout << "Invetory is full, use <unequip> first !" << std::endl;
		}
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
			delete this->_materias[idx];//doit pas delete, trouver autre moyen
		}
		this->_materias[idx] = NULL;
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
