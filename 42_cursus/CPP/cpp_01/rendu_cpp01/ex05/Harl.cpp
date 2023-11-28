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
	std::cout << "Here is some contextual informations, use it to establish your diagnosis." << std::endl;
	return;
}	

void	Harl::info(void)
{
	std::cout << "Here is some extensive informations, helpfull for tracing execution in a production environment." << std::endl;
	return;
}

void	Harl::warning(void)
{
	std::cout << "I'm warning you, there is a problem, it is still manageable but I'm warning you !" << std::endl;
	return;
}

void	Harl::error(void)
{
	std::cout << "I was not even able to warn you in time, you will have to go in manually to fix it !" << std::endl;
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
	for(int i = 0; i < 4; i++)
	{
		if (list[i].level == level)
		{
			(this->*list[i].complain)();
			return;
		}
	}
	std::cout << "I do not know how to complain with this information : " << level << std::endl;
	return;
}