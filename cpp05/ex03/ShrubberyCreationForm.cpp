#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubby", 145, 137),
	  _target("Unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubby", 145, 137),
	  _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &o)
	: AForm(o),
	  _target(o._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream file;

	file.open(_target + "_shrubbery", std::ofstream::out);
	if (!file.is_open())
		throw FileOpenError();

	file << "       @@       \n";
	file << "      *o**      \n";
	file << "     ******     \n";
	file << "    *o**o***    \n";
	file << "   ********o*   \n";
	file << "  ****o*******  \n";
	file << " ************** \n";
	file << "       ||       \n";

	file.close();
}

const char	*ShrubberyCreationForm::FileOpenError::what() const noexcept
{
	return "Error: Failed to open the file!";
}
