#pragma once

#include <iostream>

class Bureaucrat;

class Form {

	public:
		Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form &o);
		Form &operator=(const Form &o) = delete;
		~Form();

		std::string getName() const;
		bool getSignedStatus() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat &bureacrat);

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
		bool _isSigned {false};
		const int _signGrade;
		const int _executeGrade;
};

std::ostream	&operator<<(std::ostream &osteam, const Form &form);

