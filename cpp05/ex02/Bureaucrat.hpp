#pragma once

#include <iostream>

class AForm;

class Bureaucrat {

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &o);
		Bureaucrat &operator=(const Bureaucrat &o) = delete;
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(const AForm &form) const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream	&operator<<(std::ostream &osteam, const Bureaucrat &bureaucrat);
