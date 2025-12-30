#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include "Contact.hpp"

class PhoneBook {

	public:
		void addContact();
		void searchContact();
		void displayContacts();
		int getIndex(size_t &id);
		void displaySearchResult(size_t &id);

	private:
		size_t current_{0};
		size_t size_{0};
		Contact contact_[8];
};

#endif
