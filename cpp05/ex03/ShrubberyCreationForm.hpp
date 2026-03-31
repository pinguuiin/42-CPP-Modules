#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &o);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &o) = delete;
		~ShrubberyCreationForm() override;

		void executeAction() const override;

		class FileOpenError : public std::exception {
			public:
				const char *what() const noexcept override;
		};

	private:
		std::string _target;
};
