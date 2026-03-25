#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &o) : _name(o._name), _grade(o._grade) {}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

const char	*Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Error: Bureaucrat grade set too high!";
}

const char	*Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Error: Bureaucrat grade set too low!";
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

void	Bureaucrat::signForm(AForm &form)
{
	if (form.getSignedStatus() == true) {
		std::cout << getName() << " couldn't sign " << form.getName()
				  << " because form " << form.getName() << " is already signed!"
				  << std::endl;
		return ;
	}
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed form " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << " " << getName() << " couldn't sign "
				  << form.getName() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << " " << getName() << " couldn't execute "
				  << form.getName() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade "
			<< bureaucrat.getGrade() << ".";
	return ostream;
}
