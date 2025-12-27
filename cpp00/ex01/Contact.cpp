#include "Contact.hpp"

void	Contact::getString(std::string hint, std::string &prompt)
{
	while (1) {
		std::cout << hint + ":" <<std::endl;
		if (!std::getline(std::cin, prompt)) {
			std::cerr << "Failed to read input" << std::endl;
			return ;
		}
		if (!prompt.empty())
			return ;
	}
}

void	Contact::addContact()
{
	getString("First Name", firstname_);
	getString("Last Name", lastname_);
	getString("Nickname", nickname_);
	getString("Phone Number", phoneNumber_);
	getString("Darkest Secret", darkestSecret_);
}

std::string	Contact::getFirstname()
{
	return firstname_;
}

std::string	Contact::getLastname()
{
	return lastname_;
}

std::string	Contact::getNickname()
{
	return nickname_;
}

std::string	Contact::getPhoneNumber()
{
	return phoneNumber_;
}

std::string	Contact::getDarkestSecret()
{
	return darkestSecret_;
}
