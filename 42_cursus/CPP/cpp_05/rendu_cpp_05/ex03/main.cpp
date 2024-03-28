#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestedForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << std::endl << std::endl;
	{
		Intern	looser;

		try
		{
			AForm *	pform = looser.makeForm("presidential pardon", "henri");
			std::cout << *pform/* ->getName() */ << std::endl;
			// std::cout << pform->getName() << std::endl;
			delete pform;
			looser.makeForm("fait moi un formulaire", "blabla");
		}
		catch (Intern::FormDoesNotExist & except)
		{
			std::cerr << except.what() << std::endl;
		}
	}
	// std::cout << std::endl << std::endl;
	{
	}
	std::cout << std::endl << std::endl;
	return 0;
}
