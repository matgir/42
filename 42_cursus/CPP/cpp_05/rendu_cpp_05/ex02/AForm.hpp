#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:

		AForm(std::string name, int sigrade, int exgrade);
		AForm(AForm const & copy);
		virtual ~AForm(void);

		AForm	&operator=(AForm const & assign);

		const std::string	getName(void)const;
		bool				getSignature(void)const;
		int					getSiGrade(void)const;
		int					getExGrade(void)const;
		void				beSigned(Bureaucrat const & bureaucrat);
		void				execute(Bureaucrat const & executor)const;

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Form : Bureaucrats grade too high !");
				}
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Form : Bureaucrats grade too low !");
				}
		};

		class	SignedForm : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("The form is already signed !");
				}
		};

		class	NotSignedForm : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("The form isn't signed !");
				}
		};

	protected:
		virtual void	executed(void)const = 0;

	private:

		AForm(void);

		const std::string	_name;
		bool				_isSigned;
		const int			_siGrade;
		const int			_exGrade;
};

std::ostream	&operator<<(std::ostream & o, AForm const & form);

#endif

/* Now, add the execute(Bureaucrat const & executor) const member function to
the base form and implement a function to execute the form’s action of the concrete
classes. You have to check that the form is signed and that the grade of the bureaucrat
attempting to execute the form is high enough. Otherwise, throw an appropriate excep-
tion.
Whether you want to check the requirements in every concrete class or in the base
class (then call another function to execute the form) is up to you. However, one way is
prettier than the other one. */