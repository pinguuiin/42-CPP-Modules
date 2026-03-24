#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &o);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &o) = delete;
		~PresidentialPardonForm() override;

		void executeAction() const override;

	private:
		std::string _target;
};
