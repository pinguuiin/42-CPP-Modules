#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robo", 72, 45),
	  _target("Unknown") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robo", 72, 45),
	  _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &o)
	: AForm(o),
	  _target(o._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << "*zzzzzzzZZZZZ beep beep zz*" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed! try again!" << std::endl;
}
