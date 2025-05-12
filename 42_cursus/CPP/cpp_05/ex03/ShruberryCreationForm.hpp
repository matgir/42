#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"
# include <fstream>
# include <filesystem>
# include <ctime>
// # include "Bureaucrat.hpp"

// class Bureaucrat;

class ShruberryCreationForm : public AForm
{
	public:

		ShruberryCreationForm(std::string target);
		ShruberryCreationForm(ShruberryCreationForm const & copy);
		virtual ~ShruberryCreationForm(void);

		ShruberryCreationForm	&operator=(ShruberryCreationForm const & assign);

		virtual void	executed(void)const;
		std::string		getTarget(void)const;

	private:

		std::string	_target;
};

#endif

/* ShrubberyCreationForm: Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory, and writes ASCII trees
inside it. */