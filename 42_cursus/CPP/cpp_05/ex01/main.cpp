#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << std::endl << std::endl;
	{
		Form *			form = NULL;
		Bureaucrat *	brad = NULL;

		// brad = new Bureaucrat("Brad", 60);
		brad = new Bureaucrat("Brad", 12);
		form = new Form("25F", 55, 48);

		std::cout << *form << std::endl;
		std::cout << *brad << std::endl;
		
		brad->signForm(*form);
		std::cout << *form << std::endl;

		delete brad;
		delete form;
	}
	std::cout << std::endl << std::endl;
	return 0;
}
