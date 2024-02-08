#include "Form.hpp"

Form::Form(const std::string name, int sigrade, int exgrade) :
		_name(name),
		_siGrade(sigrade),
		_exGrade(exgrade)
{
	std::cout << "Form default constructor called" << std::endl;
	if (this->_siGrade < 1 || this->_exGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->_siGrade > 150 || this->_exGrade > 150)
		throw Form::GradeTooLowException();
	this->_isSigned = false;
	return;
}

Form::Form(Form const & copy) :
		_name(copy.getName()),
		_siGrade(copy.getSiGrade()),
		_exGrade(copy.getExGrade())
{
	std::cout << "Form copy constructor called" << std::endl;
	this->_isSigned = copy.getSignature();
	return;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
	return;
}

Form	&Form::operator=(Form const & assign)
{
	std::cout << "Form assignment operator called" << std::endl;

	if (this != &assign)
		this->_isSigned = assign.getSignature();
	return *this;
}

const std::string	Form::getName(void)const
{
	return this->_name;
}
bool				Form::getSignature(void)const
{
	return this->_isSigned;
}

int					Form::getSiGrade(void)const
{
	return this->_siGrade;
}

int					Form::getExGrade(void)const
{
	return this->_exGrade;
}

void				Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_siGrade)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
	return;
}

std::ostream	&operator<<(std::ostream & o, Form const & form)
{
	o << "Form : " << form.getName() << "\nGrade " << form.getSiGrade();
	o << " or higher to be signed\nGrade " << form.getExGrade();
	if (form.getSignature() == true)
		o << " or higher to be executed\nIs currently signed.";
	else if (form.getSignature() == false)
		o << " or higher to be executed\nIs currently not signed.";
	return o;
}
