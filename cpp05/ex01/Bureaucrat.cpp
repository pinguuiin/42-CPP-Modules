#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	return "Bureaucrat grade set too high!";
}

const char	*Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Bureaucrat grade set too low!";
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

void	Bureaucrat::signForm(Form &form)
{
	if (form.getSignedStatus() == true) {
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because form " << form.getName() << " is already signed!"
				  << std::endl;
		return ;
	}
	try {
		form.beSigned(*this);
		std::cout << _name << " signed form " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade "
			<< bureaucrat.getGrade() << ".";
	return ostream;
}
