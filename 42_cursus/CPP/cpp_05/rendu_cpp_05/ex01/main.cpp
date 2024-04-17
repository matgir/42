#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << std::endl << std::endl;
	{
		Form *			form = NULL;
		Bureaucrat *	brad = NULL;

		brad = new Bureaucrat("Brad", 60);
		form = new Form("25F", 55, 48);

		std::cout << *form << std::endl;
		std::cout << *brad << std::endl;
		
		brad->signForm(*form);
		for (int i = 0; i < 10; i++)
			brad->incrementGrade();
		brad->signForm(*form);
		std::cout << *form << std::endl;

		delete brad;
		delete form;
	}
	std::cout << std::endl << std::endl;
	return 0;
}
