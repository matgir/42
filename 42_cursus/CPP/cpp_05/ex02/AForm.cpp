#include "AForm.hpp"

AForm::AForm(const std::string name, int sigrade, int exgrade) :
		_name(name),
		_siGrade(sigrade),
		_exGrade(exgrade)
{
	// std::cout << "AForm initializing constructor called" << std::endl;
	if (this->_siGrade < 1 || this->_exGrade < 1)
		throw AForm::GradeTooHighException();
	else if (this->_siGrade > 150 || this->_exGrade > 150)
		throw AForm::GradeTooLowException();
	this->_isSigned = false;
	return;
}

AForm::AForm(AForm const & copy) :
		_name(copy.getName()),
		_siGrade(copy.getSiGrade()),
		_exGrade(copy.getExGrade())
{
	// std::cout << "AForm copy constructor called" << std::endl;
	this->_isSigned = copy.getSignature();
	return;
}

AForm::~AForm(void)
{
	// std::cout << "AForm destructor called" << std::endl;
	return;
}

AForm	&AForm::operator=(AForm const & assign)
{
	// std::cout << "AForm assignment operator called" << std::endl;

	if (this != &assign)
		this->_isSigned = assign.getSignature();
	return *this;
}

const std::string	AForm::getName(void)const
{
	return this->_name;
}
bool				AForm::getSignature(void)const
{
	return this->_isSigned;
}

int					AForm::getSiGrade(void)const
{
	return this->_siGrade;
}

int					AForm::getExGrade(void)const
{
	return this->_exGrade;
}

void				AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->_siGrade)
		throw AForm::GradeTooLowException();
	else if (this->_isSigned == true)
		throw AForm::SignedForm();
	else
	{
		this->_isSigned = true;
		std::cout << this->getName() << " has been signed by ";
		std::cout << bureaucrat.getName() << std::endl;
	}
	return;
}

void				AForm::execute(Bureaucrat const & executor)const
{
	if (executor.getGrade() > this->_exGrade)
		throw AForm::GradeTooLowException();
	else if (this->_isSigned == false)
		throw AForm::NotSignedForm();
	else
		executed();
}

std::ostream	&operator<<(std::ostream & o, AForm const & form)
{
	o << "AForm : " << form.getName() << "\nGrade " << form.getSiGrade();
	o << " or higher to be signed\nGrade " << form.getExGrade();
	if (form.getSignature() == true)
		o << " or higher to be executed\nIs currently signed.";
	else if (form.getSignature() == false)
		o << " or higher to be executed\nIs currently not signed.";
	return o;
}
