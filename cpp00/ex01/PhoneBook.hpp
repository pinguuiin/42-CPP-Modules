#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>

class PhoneBook {
	public:
		void addContact();
		void searchContact();
		int num;

	private:
		Contact _contact[8];
};

#endif
