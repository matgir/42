#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "";
	Zombie::_nbinst += 1;
	return;
}

Zombie::~Zombie()
{
//	std::cout << this->_name << " is no longer with us." << std::endl;
	return;
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

void	Zombie::setname(std::string name)
{
	this->_name = name;
	return;
}

void	Zombie::getnbinst()//
{//
	std::cout << Zombie::_nbinst << std::endl;//
	return;//
}//

int		Zombie::_nbinst = 0;//