#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << "================== Constructor Test ======================\n" << std::endl;

	Bureaucrat a;
	Bureaucrat c("Cici", 3);
	// AForm doc;
	ShrubberyCreationForm gdoc("black");
	ShrubberyCreationForm ggdoc(gdoc);
	RobotomyRequestForm ydoc("Cemini");
	RobotomyRequestForm yydoc(ydoc);
	PresidentialPardonForm rdoc("Rational Pie");
	PresidentialPardonForm rrdoc(rdoc);

	std::cout << a << std::endl;
	std::cout << c << std::endl;
	std::cout << gdoc << std::endl;
	std::cout << ggdoc << std::endl;
	std::cout << ydoc << std::endl;
	std::cout << yydoc << std::endl;
	std::cout << rdoc << std::endl;
	std::cout << rrdoc << std::endl;

	std::cout << "\n================== Form Execution Test ==================\n" << std::endl;

	Bureaucrat Manager("Manager", 149);
	Bureaucrat sManager("sManager", 70);
	Bureaucrat ssManager("ssManager", 40);
	Bureaucrat ceo("ceo", 1);

	// -------Shrubbery-------
	std::cout << "Not signed form:" << std::endl;
	sManager.executeForm(gdoc);
	std::cout << "\nSigner's grade too low:" << std::endl;
	Manager.signForm(gdoc);
	std::cout << "\nSigner's grade enough:" << std::endl;
	sManager.signForm(gdoc);
	std::cout << "\nExecutor's grade too low:" << std::endl;
	Manager.executeForm(gdoc);
	std::cout << "\nExecutor's grade enough:" << std::endl;
	sManager.executeForm(gdoc);
	std::cout << "\n(Overwrite old shrubbery file)" << std::endl;
	sManager.executeForm(gdoc);

	std::cout << std::endl;

	// -------Robotomy-------
	sManager.signForm(ydoc);
	ssManager.executeForm(ydoc);

	std::cout << std::endl;

	// -------Presidential-------
	ceo.signForm(rdoc);
	ceo.executeForm(rdoc);

	std::cout << "\n================== Robotomy Test ========================\n" << std::endl;

	for (int i = 0; i < 20; ++i) {
		ssManager.executeForm(ydoc);
		std::cout << std::endl;
	}

	return 0;
}
