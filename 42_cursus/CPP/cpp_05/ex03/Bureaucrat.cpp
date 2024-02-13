#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	this->_grade = grade;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	// std::cout << "Bureaucrat " << this->_name << ", grade " << this->_grade;
	// std::cout << ", initialising constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy.getName())
{
	this->_grade = copy.getGrade();
	// std::cout << "Bureaucrat " << this->_name << ", grade " << this->_grade;
	// std::cout << ", copy constructor called" << std::endl;
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	// std::cout << "Bureaucrat destructor called" << std::endl;
	return;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const & assign)
{
	// std::cout << "Bureaucrat assignment operator called" << std::endl;

	if (this != &assign)
		this->_grade = assign.getGrade();
	return *this;
}

const std::string	Bureaucrat::getName(void)const
{
	return this->_name;
}

int					Bureaucrat::getGrade(void)const
{
	return this->_grade;
}

void				Bureaucrat::incrementGrade(void)
{
	this->_grade -= 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		std::cout << this->_name << " is now grade " << this->_grade << std::endl;
}

void				Bureaucrat::decrementGrade(void)
{
	this->_grade += 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		std::cout << this->_name << " is now grade " << this->_grade << std::endl;
}

void				Bureaucrat::signForm(AForm & form)const
{
	try
	{
		form.beSigned(*this);
		// std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException & except)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName();
		std::cout << " because his grade is too low" << std::endl;
	}
	catch (AForm::SignedForm & except)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName();
		std::cout << " because it is already signed" << std::endl;
	}
	return;
}

void				Bureaucrat::executeForm(AForm const & form)const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException & except)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName();
		std::cout << " because his grade is too low" << std::endl;
	}
	catch (AForm::NotSignedForm & except)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName();
		std::cout << " because it is not signed" << std::endl;
	}
}

std::ostream	&operator<<(std::ostream & o, Bureaucrat const & bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	o << ".";
	return o;
}