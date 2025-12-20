#include "PhoneBook.hpp"

void	saveInfoToContact(PhoneBook pbk, std::string hint) {

	std::string prompt;

	std::cout << hint << ":" <<std::endl;
	std::getline(std::cin, prompt);
}

void	addContact(PhoneBook pbk) {

	saveInfoToContact(pbk, "firstname");
	saveInfoToContact(pbk, "lastname");
	saveInfoToContact(pbk, "nickname");
	saveInfoToContact(pbk, "phone number");
	saveInfoToContact(pbk, "darkest secret");
}

int	main() {

	PhoneBook pbk;
	std::string prompt;

	std::cout << "Please enter one of the three operations: ADD, SEARCH or EXIT" << std::endl;
	for (;;) {
		std::getline(std::cin, prompt);
		if (prompt == "ADD")
			addContact(pbk);
		else if (prompt == "SEARCH")
			searchContact(pbk);
		else if (prompt == "EXIT")
			exitProgram();
	}
	return 0;
}
