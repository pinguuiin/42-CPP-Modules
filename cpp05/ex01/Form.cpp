#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signGrade(1), _executeGrade(1) {}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name),
	_signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &o) : _name(o._name), _isSigned(o._isSigned),
	_signGrade(o._signGrade), _executeGrade(o._executeGrade) {}

Form::~Form() {}

std::string	Form::getName() const
{
	return _name;
}

bool	Form::getSignedStatus() const
{
	return _isSigned;
}

int	Form::getSignGrade() const
{
	return _signGrade;
}

int	Form::getExecuteGrade() const
{
	return _executeGrade;
}

void	Form::beSigned(const Bureaucrat &bureacrat)
{
	if (bureacrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char	*Form::GradeTooHighException::what() const noexcept
{
	return "Grade is too high!";
}

const char	*Form::GradeTooLowException::what() const noexcept
{
	return "Grade is too low!";
}

std::ostream	&operator<<(std::ostream &ostream, const Form &form)
{
	ostream << "Form " << form.getName() << ", signing grade " << form.getSignGrade()
			<< ", execution grade " << form.getExecuteGrade() << ", is"
			<< (form.getSignedStatus() == true ? " " : " not ") << "signed";
	return ostream;
}
