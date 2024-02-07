// replace canonical by your class name
// replace variable by your variable name

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{
	public:

		// Bureaucrat(void);//peut etre effacer et remplacer par constructor n'accpetant que name et grade
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & copy);
		virtual ~Bureaucrat(void);

		Bureaucrat	&operator=(Bureaucrat const & assign);

		std::string	getName(void)const;
		int			getGrade(void)const;
		void		incrementGrade(void);
		void		decrementGrade(void);

		class	GradeTooHighException : std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Grade too High !");
				}
		};

		class	GradeTooLowException : std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Grade too Low !");
				}
		};


	private:

		std::string	_name;
		int			_grade;
};

std::ostream	&operator<<(std::ostream & o, Bureaucrat const & bureaucrat);

#endif

// Bureaucrat::Bureaucrat(void)//
// {
	// std::cout << "Bureaucrat default constructor called" << std::endl;
	// this->_name = "Bureaucrat name";
	// this->_grade = 0;
	// return;
// }
