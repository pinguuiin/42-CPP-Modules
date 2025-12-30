#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {

	public:
		void assignAttribute(std::string hint, std::string &prompt);
		void addContact();
		std::string getFirstname();
		std::string getLastname();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();

	private:
		std::string firstname_;
		std::string lastname_;
		std::string nickname_;
		std::string phoneNumber_;
		std::string darkestSecret_;
};

#endif
