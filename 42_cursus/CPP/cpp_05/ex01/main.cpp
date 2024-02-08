#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << std::endl << std::endl;
	{
		Form *	form = NULL;
		form = new Form("25F", 55, 48);
		std::cout << *form << std::endl;
		delete form;
	}
	std::cout << std::endl << std::endl;
	return 0;
}
