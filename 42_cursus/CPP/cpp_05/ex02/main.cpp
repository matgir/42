#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestedForm.hpp"
#include "ShruberryCreationForm.hpp"

void	trythings(Bureaucrat * b, AForm * pf, AForm * rf, AForm * sf)
{
		b->signForm(*sf);
		b->signForm(*rf);
		b->signForm(*pf);
		b->executeForm(*sf);
		b->executeForm(*rf);
		b->executeForm(*pf);
		std::cout << std::endl << std::endl;
}

void	increase(Bureaucrat * b, int j)
{
		for (int i = 0; i < j; i++)
			b->incrementGrade();
		std::cout << std::endl << std::endl;

}

int	main(void)
{
	std::cout << std::endl << std::endl;
	{
		AForm *	pform = new PresidentialPardonForm("Anguerand");
		AForm *	rform = new RobotomyRequestForm("Meriadoc");
		AForm *	sform = new ShruberryCreationForm("garden");

		Bureaucrat *	hermes = new Bureaucrat("Hermes", 150);

		trythings(hermes, pform, rform, sform);
		increase(hermes, 5);
		trythings(hermes, pform, rform, sform);
		increase(hermes, 8);
		trythings(hermes, pform, rform, sform);
		increase(hermes, 65);
		trythings(hermes, pform, rform, sform);
		increase(hermes, 27);
		trythings(hermes, pform, rform, sform);
		increase(hermes, 20);
		trythings(hermes, pform, rform, sform);
		increase(hermes, 20);
		trythings(hermes, pform, rform, sform);

		delete hermes;
		delete pform;
		delete rform;
		delete sform;
	}
	std::cout << std::endl << std::endl;
	{
		AForm *	rform = new RobotomyRequestForm("Meriadoc");
		Bureaucrat *	hermes = new Bureaucrat("Hermes", 44);

		hermes->signForm(*rform);
		for (int i = 0; i < 1000000; i++)
			hermes->executeForm(*rform);

		delete hermes;
		delete rform;
	}
	std::cout << std::endl << std::endl;
	return 0;
}
