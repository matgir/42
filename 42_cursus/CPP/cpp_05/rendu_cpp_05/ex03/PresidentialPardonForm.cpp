#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
		AForm("Presidential_Pardon_form", 25, 5)
{
	this->_target = target;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) :
		AForm(copy)
{
	this->_target = copy.getTarget();
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const & assign)
{
	AForm::operator=(assign);
	if (this != &assign)
		this->_target = assign.getTarget();
	return *this;
}

void		PresidentialPardonForm::executed(void)const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox";
	std::cout << std::endl;
	return;
}

std::string	PresidentialPardonForm::getTarget(void)const
{
	return this->_target;
}

/* PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox. */