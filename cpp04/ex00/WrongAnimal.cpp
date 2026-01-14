#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal")
{
	std::cout << "WrongAnimal is created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "WrongAnimal is created as a copy of " << other.type_ << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		type_ = other.type_;
	std::cout << "WrongAnimal is reassigned by " << other.type_ << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal is destroyed" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal: Hello hello just hello" << std::endl;
}

const std::string	&WrongAnimal::getType() const
{
	return type_;
}
