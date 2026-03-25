#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signGrade(1), _executeGrade(1) {}

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name),
	_signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &o) : _name(o._name), _isSigned(o._isSigned),
	_signGrade(o._signGrade), _executeGrade(o._executeGrade) {}

AForm::~AForm() {}

std::string	AForm::getName() const
{
	return _name;
}

bool	AForm::getSignedStatus() const
{
	return _isSigned;
}

int	AForm::getSignGrade() const
{
	return _signGrade;
}

int	AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void	AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (_isSigned == false)
		throw UnsignedFormException();
	if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
	executeAction();
}

const char	*AForm::GradeTooHighException::what() const noexcept
{
	return "Error: Grade is too high!";
}

const char	*AForm::GradeTooLowException::what() const noexcept
{
	return "Error: Grade is too low!";
}

const char	*AForm::UnsignedFormException::what() const noexcept
{
	return "Error: Form needs to be signed first!";
}

std::ostream	&operator<<(std::ostream &ostream, const AForm &form)
{
	ostream << "Form " << form.getName() << ", signing grade " << form.getSignGrade()
			<< ", execution grade " << form.getExecuteGrade() << ", is"
			<< (form.getSignedStatus() == true ? " " : " not ") << "signed";
	return ostream;
}
