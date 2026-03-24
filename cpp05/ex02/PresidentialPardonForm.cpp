#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("President", 25, 5),
	  _target("Unknown") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("President", 25, 5),
	  _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &o)
	: AForm(o),
	  _target(o._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
