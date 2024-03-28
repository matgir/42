#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestedForm.hpp"
# include "ShruberryCreationForm.hpp"

class Intern
{
	public:

		Intern(void);
		Intern(Intern const & copy);
		virtual ~Intern(void);

		Intern	&operator=(Intern const & assign);

		AForm *	makeForm(std::string formName, std::string target);

		typedef AForm *	(Intern::*formPtr)(std::string target);
		typedef struct s_Intern
		{
			std::string	name;
			formPtr		form;
		} formList;

		class	FormDoesNotExist : std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("The form you ask to create does not exist !");
				}
		};

	protected:
		
		AForm * makeShrub(std::string target);
		AForm * makeRobotomy(std::string target);
		AForm * makePardon(std::string target);
};

#endif
