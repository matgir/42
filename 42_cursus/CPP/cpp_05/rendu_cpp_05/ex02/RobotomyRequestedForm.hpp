#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"
# include <ctime>
// # include "Bureaucrat.hpp"

// class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:

		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & copy);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(RobotomyRequestForm const & assign);

		virtual void	executed(void)const;
		std::string		getTarget(void)const;

	private:

		RobotomyRequestForm(void);
		
		std::string	_target;
};

#endif

/* RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed. */