#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout <<"Default Brain constructor called" << std::endl;
	return;
}

Brain::Brain(Brain const & copy)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy.getIdeas(i);
	std::cout << "Copy Brain constructor called" << std::endl;
	return;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return;
}

Brain	&Brain::operator=(Brain const & assign)
{
	std::cout << "Brain assignment operator called" << std::endl;

	if (this != &assign)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = assign.getIdeas(i);
	}
	return *this;
}

std::string	Brain::getIdeas(const int & i)const
{
	return this->_ideas[i];
}

void		Brain::setIdeas(const std::string & idea, const int & i)
{
	this->_ideas[i] = idea;
}