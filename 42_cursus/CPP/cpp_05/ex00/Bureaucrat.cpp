#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->_name = name;
	this->_grade = grade;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat " << this->_name << ", grade " << this->_grade;
	std::cout << ", initialising constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy)
{
	this->_name = copy.getName();
	this->_grade = copy.getGrade();
	std::cout << "Bureaucrat " << this->_name << ", grade " << this->_grade;
	std::cout << ", copy constructor called" << std::endl;
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const & assign)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;

	if (this != &assign)
	{
		this->_name = assign.getName();
		this->_grade = assign.getGrade();
	}
	return *this;
}

std::string	Bureaucrat::getName(void)const
{
	return this->_name;
}

int			Bureaucrat::getGrade(void)const
{
	return this->_grade;
}

void		Bureaucrat::incrementGrade(void)
{
	this->_grade -= 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void		Bureaucrat::decrementGrade(void)
{
	this->_grade += 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream & o, Bureaucrat const & bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	o << "."/*  << std::endl */;
	return o;
}