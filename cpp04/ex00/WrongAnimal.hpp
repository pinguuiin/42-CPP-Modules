#pragma once

#include <iostream>
#include <string>

class WrongAnimal {

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		~WrongAnimal();

		void makeSound() const;
		const std::string &getType() const;

	protected:
		std::string type_;
};
