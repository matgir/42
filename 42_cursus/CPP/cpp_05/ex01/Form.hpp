#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

		Form(std::string name, int sigrade, int exgrade);
		Form(Form const & copy);
		virtual ~Form(void);

		Form	&operator=(Form const & assign);

		const std::string	getName(void)const;
		bool				getSignature(void)const;
		int					getSiGrade(void)const;
		int					getExGrade(void)const;
		void				beSigned(Bureaucrat const & bureaucrat);

		class	GradeTooHighException : std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Form : grade too high !");
				}
		};

		class	GradeTooLowException : std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Form : grade too low !");
				}
		};

	private:

		Form(void);
		
		const std::string	_name;
		bool				_isSigned;
		const int			_siGrade;
		const int			_exGrade;
};

std::ostream	&operator<<(std::ostream & o, Form const & form);

#endif
