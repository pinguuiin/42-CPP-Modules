#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm	*Intern::makeForm(std::string name, std::string target) const
{

	std::string formName[3] = {"Shrubby", "Robo", "President"};
	AForm *form;
	int i;

	for (i = 0; i < 3 && formName[i] != name; ++i);

	switch (i) {
		case 0:
			form = new ShrubberyCreationForm(target);
			break ;
		case 1:
			form = new RobotomyRequestForm(target);
			break ;
		case 2:
			form = new PresidentialPardonForm(target);
			break ;
		default:
			std::cout << "Intern couldn't understand your request" << std::endl;
			return nullptr;
	}

	std::cout << "Intern creates " << form->getName() << std::endl;

	return form;
}
