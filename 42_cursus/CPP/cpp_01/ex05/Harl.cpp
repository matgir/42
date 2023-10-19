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
	std::cout << "Here is some contextual information, use it to establish your diagnosis." << std::endl;
	return;
}

void	Harl::info(void)
{
	std::cout << "Here is some detailled informations, you can now follow the execution of your programme." << std::endl;
	return;
}

void	Harl::warning(void)
{
	std::cout << "I'm warning you, it is still manageable but i'm warning you !" << std::endl;
	return;
}

void	Harl::error(void)
{
	std::cout << "I was not even able to warn you, it is now KAPUT so dif in and fix it !" << std::endl;
	return;
}

void	Harl::complain(std::string level)
{
	return;
}