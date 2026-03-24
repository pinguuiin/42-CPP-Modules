#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &o);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &o) = delete;
		~RobotomyRequestForm() override;

		void executeAction() const override;

	private:
		std::string _target;
};
