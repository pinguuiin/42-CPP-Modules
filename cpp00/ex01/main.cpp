#include "PhoneBook.hpp"

int	main()
{
	PhoneBook pbk;
	std::string prompt;

	while (1) {
		std::cout << "Please enter one of the three operations: ADD, SEARCH or EXIT" << std::endl;
		if (!std::getline(std::cin, prompt))
			break ;
		if (prompt == "ADD")
			pbk.addContact();
		else if (prompt == "SEARCH")
			pbk.searchContact();
		else if (prompt == "EXIT")
			return 0;
		else
			continue ;
	}
	std::cerr << "Failed to read input" << std::endl;
	return 1;
}
