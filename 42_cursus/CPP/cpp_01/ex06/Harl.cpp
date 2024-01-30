#include "Harl.hpp"

Harl::Harl()
{
	return;
}

Harl::~Harl()
{
	return;
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "Here is some contextual informations, use it to establish your ";
	std::cout << "diagnosis." << std::endl << std::endl;
	this->complain("INFO");
	return;
}	

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Here is some extensive informations, helpfull for tracing execution ";
	std::cout << "in a production environment." << std::endl << std::endl;
	this->complain("WARNING");
	return;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I'm warning you, there is a problem, it is still manageable but ";
	std::cout << "I'm warning you !" << std::endl << std::endl;
	this->complain("ERROR");
	return;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "I was not even able to warn you in time, you will have to go in ";
	std::cout << "manually to fix it !" << std::endl << std::endl;
	return;
}

void	Harl::complain(std::string level)
{
	complainlist	list[4] = 
	{
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error},
	};
	int				j;

	for(int i = 0; i < 4; i++)
		if (list[i].level == level)
			j = i;
	switch (j)
	{
		case 0:
			(this->*list[j].complain)();
			break;
		case 1:
			(this->*list[j].complain)();
			break;
		case 2:
			(this->*list[j].complain)();
			break;
		case 3:
			(this->*list[j].complain)();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	return;
}
