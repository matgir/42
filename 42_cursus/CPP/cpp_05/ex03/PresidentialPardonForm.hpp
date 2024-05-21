#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"
// # include "Bureaucrat.hpp"

// class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:

		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(PresidentialPardonForm const & assign);

		virtual void	executed(void)const;
		std::string		getTarget(void)const;

	private:

		std::string	_target;
};

#endif
