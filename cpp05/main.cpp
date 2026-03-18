#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "================== Constructor Test ======================\n" << std::endl;

	Bureaucrat a;
	Bureaucrat b("Bebe", 2);
	Bureaucrat bb(b);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << bb << std::endl;

	try {
		Bureaucrat c("Cici", 145);
		std::cout << c << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Couldn't construct: " << e.what() << std::endl;
	}

	try {
		Bureaucrat d("WeeWee", 1000);
		std::cout << d << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Couldn't construct: " << e.what() << std::endl;
	}

	std::cout << "\n================== Grade Boundary Test ===================\n" << std::endl;

	try {
		a.incrementGrade();
		std::cout << a.getName() << "'s grade increased!" << std::endl;
		std::cout << a << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Couldn't increment: " << e.what() << std::endl;
	}

	Bureaucrat c("Cici", 145);
	std::cout << c << std::endl;

	for (int i = 0; i < 20; ++i) {
		try {
			c.decrementGrade();
			std::cout << c.getName() << "'s grade decreased!" << std::endl;
			std::cout << c << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Couldn't decrement: " << e.what() << std::endl;
			break ;
		}
	}

	return 0;
}
