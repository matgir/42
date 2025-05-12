#include "MateriaSource.hpp"

MateriaSoucre::MateriaSoucre(void)
{
	// std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_learnedMaterias[i] = NULL;
	return;
}

MateriaSoucre::MateriaSoucre(MateriaSoucre const & copy)
{
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnedMaterias[i])
			delete this->_learnedMaterias[i];
		this->_learnedMaterias[i] = NULL;
		if (copy.getMateria(i))
			this->_learnedMaterias[i] = copy.getMateria(i)->clone();
	}
}

MateriaSoucre::~MateriaSoucre(void)
{
	// std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if(this->_learnedMaterias[i])
			delete this->_learnedMaterias[i];
	return;
}

MateriaSoucre	&MateriaSoucre::operator=(MateriaSoucre const & assign)
{
	// std::cout << "MateriaSource assignment operator called" << std::endl;

	if (this != &assign)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_learnedMaterias[i])
				delete this->_learnedMaterias[i];
			this->_learnedMaterias[i] = NULL;
			if (assign.getMateria(i))
				this->_learnedMaterias[i] = assign.getMateria(i)->clone();
		}
	}
	return *this;
}

AMateria	*MateriaSoucre::getMateria(int idx)const
{
	if (this->_learnedMaterias[idx])
		return this->_learnedMaterias[idx];
	else
	{
		std::cout << "There is no Materia at slot " << idx << " !" << std::endl;
		return NULL;
	}
}

void		MateriaSoucre::learnMateria(AMateria * m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!this->_learnedMaterias[i])
			{
				this->_learnedMaterias[i] = m->clone();
				return;
			}
			if (this->_learnedMaterias[i])
				if (i == 3)
					std::cout << "MateriaSource inventory is full !" << std::endl;
		}
	}
	else
		std::cout << "The Materia you are trying to learn is empty" << std::endl;
}

AMateria *	MateriaSoucre::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		// if (this->_learnedMaterias[i])
			// std::cout << this->_learnedMaterias[i]->getType() << std::endl;
		if (this->_learnedMaterias[i] && this->_learnedMaterias[i]->getType() == type)
			return this->_learnedMaterias[i]->clone();
	}
	std::cout << "There is no " << type << " materia in this inventory !" << std::endl;
	return NULL;
}
