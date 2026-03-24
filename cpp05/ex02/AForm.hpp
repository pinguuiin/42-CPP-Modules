#pragma once

#include <iostream>

class Bureaucrat;

class AForm {

	public:
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm &o);
		AForm &operator=(const AForm &o) = delete;
		virtual ~AForm();

		std::string getName() const;
		bool getSignedStatus() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat &signer);
		void execute(const Bureaucrat &executor) const;
		virtual void executeAction() const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
		class UnsignedFormException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

	private:
		const std::string _name;
		bool _isSigned {false};
		const int _signGrade;
		const int _executeGrade;
};

std::ostream	&operator<<(std::ostream &osteam, const AForm &form);

