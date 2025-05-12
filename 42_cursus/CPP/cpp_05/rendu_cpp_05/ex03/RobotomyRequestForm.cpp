#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
		AForm("Robotomy_Request_Form", 72, 45)
{
	this->_target = target;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) :
		AForm(copy)
{
	this->_target = copy.getTarget();
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const & assign)
{
	AForm::operator=(assign);
	if (this != &assign)
		this->_target = assign.getTarget();
	return *this;
}

void		RobotomyRequestForm::executed(void)const
{
	std::cout << "DRIIIIIIIIIIIIIIIIIIIIIIIIIIIIILLING" << std::endl;
	std::cout << "DRIIIIIIIIIIIIIIIIIIIIIIIIIIIIILLING" << std::endl;
	if (RobotomyRequestForm::_nbRob % 2 == 0)
		std::cout << this->_target << " has been robotomized !" << std::endl;
	else
		std::cout << "The robotomy failed !" << std::endl;
	RobotomyRequestForm::_nbRob++;
	return;
}

std::string	RobotomyRequestForm::getTarget(void)const
{
	return this->_target;
}

int	RobotomyRequestForm::_nbRob = 0;
