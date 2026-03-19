#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "================== Constructor Test ======================\n" << std::endl;

	Bureaucrat a;
	Bureaucrat c("Cici", 7);
	Form doc;
	Form gdoc("green doc", 2, 50);
	Form gcopy(gdoc);

	std::cout << a << std::endl;
	std::cout << c << std::endl;
	std::cout << doc << std::endl;
	std::cout << gdoc << std::endl;
	std::cout << gcopy << std::endl;

	// Try to construct with too low grade
	try {
		Form rdoc("red doc", 200, 1);
		std::cout << rdoc << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Couldn't construct: " << e.what() << std::endl;
	}

	// Try to construct with too high grade
	try {
		Form ydoc("yellow doc", 5, -5);
		std::cout << ydoc << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Couldn't construct: " << e.what() << std::endl;
	}

	std::cout << "\n================== Form Signing Test ====================\n" << std::endl;

	std::cout << gdoc << "\n" << std::endl;

	for (int i = 0; i < 10; ++i) {
		try {
			c.incrementGrade();
			std::cout << c.getName() << "'s grade increased!" << std::endl;
			std::cout << c << std::endl;
			c.signForm(gdoc);
			std::cout << gdoc << "\n" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Couldn't increment: " << e.what() << std::endl;
			break ;
		}
	}

	return 0;
}
