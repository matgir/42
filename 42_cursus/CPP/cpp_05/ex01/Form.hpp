// replace canonical by your class name
// replace variable by your variable name

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form
{
	public:

		Form(std::string name, int sigrade, int exgrade);
		Form(Form const & copy);
		virtual ~Form(void);

		Form	&operator=(Form const & assign);

		std::string	getName(void)const;
		bool		getSignature(void)const;
		int			getSiGrade(void)const;
		int			getExGrade(void)const;
		void		beSigned(Bureaucrat const & bureaucrat);

		class	GradeTooHighException : std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Form : grade too high !")
				}
		};

		class	GradeTooLowException : std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Form : grade too low !")
				}
		};

	private:

		std::string const	_name;
		bool				_signed;
		int const			_siGrade;
		int const			_exGrade;
};

std::ostream	&operator<<(std::ostream & o, Form const & form);

#endif

Form::Form(std::string name, int sigrade, int exgrade)
{
	std::cout << "Form default constructor called" << std::endl;
	this->_name = name;
	this->_signed = false;
	this->_siGrade = sigrade;
	thsi->_exGrade = exgrade;
	return;
}

Form::Form(Form const & copy)
{
	std::cout << "Form copy constructor called" << std::endl;
	this->_name = copy.getName();
	this->_signed = copy.getSignature();
	this->_siGrade = copy.getSiGrade();
	this->_exGrade = copy.getExGrade();
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
	{
		this->_name = copy.getName();
		this->_signed = copy.getSignature();
		this->_siGrade = copy.getSiGrade();
		this->_exGrade = copy.getExGrade();
	}
	return *this;
}

std::string	Form::getName(void)const
{
	return this->_name;
}
bool		Form::getSignature(void)const
{
	return this->_signed;
}

int			Form::getSiGrade(void)const
{
	return this->_siGrade;
}

		int			getExGrade(void)const;
		void		beSigned(Bureaucrat const & bureaucrat);

std::ostream	&operator<<(std::ostream & o, Form const & form);
