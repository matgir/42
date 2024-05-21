#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:

		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & copy);
		virtual ~Bureaucrat(void);

		Bureaucrat	&operator=(Bureaucrat const & assign);

		const std::string	getName(void)const;
		int					getGrade(void)const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(AForm & form)const;
		void				executeForm(AForm const & form)const;

		class	GradeTooHighException : std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Bureaucrat : grade too high !");
				}
		};

		class	GradeTooLowException : std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Bureaucrat : grade too low !");
				}
		};


	private:

		const std::string	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream & o, Bureaucrat const & bureaucrat);

#endif

/* Lastly, add the executeForm(AForm const & form) member function to the Bureau-
crat. It must attempt to execute the form. If it’s successful, print something like:
<bureaucrat> executed <form>
If not, print an explicit error message.
Implement and turn in some tests to ensure everything works as expected. */