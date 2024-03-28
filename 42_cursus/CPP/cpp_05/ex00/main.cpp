#include "Bureaucrat.hpp"

int	main(void)
{
	// std::cout << std::endl << std::endl;
	{
		// Bureaucrat *	bernard1222 = new Bureaucrat("Bernard", 1222);//
	}
	std::cout << std::endl << std::endl;
	{
		Bureaucrat * bernard = NULL;
		try
		{
			bernard = new Bureaucrat("Bernard", 652);
			// bernard = new Bureaucrat("Bernard", 150);
			// bernard = new Bureaucrat();
			bernard->decrementGrade();
			for (int i = 0; i < 65; i++)
				bernard->incrementGrade();
			std::cout << *bernard << std::endl;
			for (int i = 0; i < 70; i++)
				bernard->decrementGrade();
			std::cout << *bernard << std::endl;
			delete(bernard);
		}
		catch (Bureaucrat::GradeTooHighException & except)
		{
			std::cerr << except.what() << std::endl;
			delete(bernard);
		}
		catch (Bureaucrat::GradeTooLowException & except)
		{
			std::cerr << except.what() << std::endl;
			delete(bernard);
		}
	}
	std::cout << std::endl << std::endl;
	{
		Bureaucrat * bernard = NULL;
		Bureaucrat * benoit = NULL;
		try
		{
			bernard = new Bureaucrat("Bernard", 150);
			*benoit = *bernard;
			benoit = new Bureaucrat(*bernard);
			for (int i = 0; i < 65; i++)
				bernard->incrementGrade();
			std::cout << *bernard << std::endl;
			std::cout << *benoit << std::endl;
			delete(bernard);
		}
		catch (Bureaucrat::GradeTooHighException & except)
		{
			std::cerr << except.what() << std::endl;
			delete(bernard);
		}
		catch (Bureaucrat::GradeTooLowException & except)
		{
			std::cerr << except.what() << std::endl;
			delete(bernard);
		}
	}
	std::cout << std::endl << std::endl;
	{
		Bureaucrat * bernard = NULL;
		try
		{
			bernard = new Bureaucrat("Bernard", 150);
			for (int i = 0; i < 65; i++)
				bernard->incrementGrade();
			std::cout << *bernard << std::endl;
			for (int i = 0; i < 70; i++)
				bernard->decrementGrade();
			std::cout << *bernard << std::endl;
			delete(bernard);
		}
		catch (Bureaucrat::GradeTooHighException & except)
		{
			std::cerr << except.what() << std::endl;
			delete(bernard);
		}
		catch (Bureaucrat::GradeTooLowException & except)
		{
			std::cerr << except.what() << std::endl;
			delete(bernard);
		}
	}
	std::cout << std::endl << std::endl;
	return 0;
}
