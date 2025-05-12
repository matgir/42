#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
	return;
}

Intern::Intern(Intern const & copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)copy;
	return;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
	return;
}

Intern	&Intern::operator=(Intern const & assign)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)assign;
	return *this;
}

AForm *	Intern::makeForm(std::string formName, std::string target)
{
	formList	list[12] = 
	{
		{"shruberry creation", &Intern::makeShrub},
		{"Shruberry Creation", &Intern::makeShrub},
		{"shruberry Creation", &Intern::makeShrub},
		{"Shruberry Creation", &Intern::makeShrub},
		{"robotomy request", &Intern::makeRobotomy},
		{"Robotomy Request", &Intern::makeRobotomy},
		{"Robotomy request", &Intern::makeRobotomy},
		{"robotomy Request", &Intern::makeRobotomy},
		{"presidential pardon", &Intern::makePardon},
		{"Presidential Pardon", &Intern::makePardon},
		{"Presidential pardon", &Intern::makePardon},
		{"presidential Pardon", &Intern::makePardon},
	};

	for(int i = 0; i < 12; i++)
	{
		if (list[i].name == formName)
		{
			AForm *	form = (this->*list[i].form)(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	throw Intern::FormDoesNotExist();
	return NULL;
}

AForm * Intern::makeShrub(std::string target)
{
	return new ShruberryCreationForm(target);
}

AForm * Intern::makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm * Intern::makePardon(std::string target)
{
	return new PresidentialPardonForm(target);
}
