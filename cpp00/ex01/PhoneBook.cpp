#include "PhoneBook.hpp"

void	PhoneBook::addContact()
{
	contact_[current_].addContact();
	current_ = (current_ == 7) ? 0 : current_ + 1;
	size_ = (size_ < 8) ? size_ + 1 : size_;
}

static std::string	truncate(std::string const &str)
{
	return str.length() > 10 ? str.substr(0, 9) + "." : str;
}

void	PhoneBook::displayContacts()
{
	std::cout << "|" << std::setw(10) << "Index"
			  << "|" << std::setw(10) << "First Name"
			  << "|" << std::setw(10) << "Last Name"
			  << "|" << std::setw(10) << "Nickname"
			  << "|" << std::endl;
	for (size_t id = 0; id < size_; ++id) {
		std::cout << "|" << std::setw(10) << id
				  << "|" << std::setw(10) << truncate(contact_[id].getFirstname())
				  << "|" << std::setw(10) << truncate(contact_[id].getLastname())
				  << "|" << std::setw(10) << truncate(contact_[id].getNickname())
				  << "|" << std::endl;
	}
}

int	PhoneBook::getIndex(size_t &id)
{
	std::string prompt;

	while (1) {
		std::cout << "Please input index:" << std::endl;
		if (!std::getline(std::cin, prompt)) {
			std::cerr << "Failed to read entry index" << std::endl;
			return 1;
		}
		if (prompt.length() != 1 || !std::isdigit(prompt[0]))
			continue ;
		id = std::stoi(prompt);
		if (id < size_)
			return 0;
	}
}

void	PhoneBook::displaySearchResult(size_t &id)
{
	Contact &result = contact_[id];

	std::cout << "First Name: " << result.getFirstname() << std::endl;
	std::cout << "Last Name: " << result.getLastname() << std::endl;
	std::cout << "Nickname: " << result.getNickname() << std::endl;
	std::cout << "Phone Number: " << result.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << result.getDarkestSecret() << std::endl;
}

void	PhoneBook::searchContact()
{
	size_t id;

	if (size_ == 0) {
		std::cout << "No saved contact" << std::endl;
		return ;
	}
	displayContacts();
	if (getIndex(id))
		return ;
	displaySearchResult(id);
}
