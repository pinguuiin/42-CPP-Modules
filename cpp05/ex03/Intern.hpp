#pragma once

#include <string>

class AForm;

class Intern {

	public:
		Intern();
		Intern(const Intern &o) = delete;
		Intern &operator=(const Intern &o) = delete;
		~Intern();

		AForm *makeForm(std::string name, std::string target) const;
};
