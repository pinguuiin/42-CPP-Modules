#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << "\n================== Make Form Test ======================\n" << std::endl;

	Intern noname;
	AForm *form;
	AForm *shrubby;
	AForm *robo;
	AForm *president;

	// nonexist form
	try {
		std::cout << "[Trying to create nonexistent form...]" << std::endl;
		form = noname.makeForm("Blbie", "hawaii");
		if (form) {
			std::cout << *form << "\nDeleting Blbie..." << std::endl;
			delete form;
		}
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// ShrubberyCreationForm
	try {
		std::cout << "[Trying to create ShrubberyCreationForm...]" << std::endl;
		shrubby = noname.makeForm("Shrubby", "silver");
		if (shrubby) {
			std::cout << *shrubby << "\nDeleting Shrubby..." << std::endl;
			delete shrubby;
		}
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// RobotomyRequestForm
	try {
		std::cout << "[Trying to create RobotomyRequestForm...]" << std::endl;
		robo = noname.makeForm("Robo", "Clause");
		if (robo) {
			std::cout << *robo << "\nDeleting Robo..." << std::endl;
			delete robo;
		}
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// PresidentialPardonForm
	try {
		std::cout << "[Trying to create PresidentialPardonForm...]" << std::endl;
		president = noname.makeForm("President", "Nini");
		if (president) {
			std::cout << *president << "\nDeleting President..." << std::endl;
			delete president;
		}
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
