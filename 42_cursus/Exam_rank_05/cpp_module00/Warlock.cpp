#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

std::string const &	Warlock::getName(void)const
{
	return this->_name;
}

std::string const &	Warlock::getTitle(void)const
{
	return this->_title;
}

void				Warlock::setTitle(std::string const & newTitle)
{
	this->_title = newTitle;
}

void				Warlock::introduce(void)const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

Warlock::Warlock(void)
{
	return;
}

Warlock::Warlock(Warlock const & copy)
{
	(void)copy;
	return;
}

Warlock				&Warlock::operator=(Warlock const & assign)
{
	(void)assign;
	return *this;
}