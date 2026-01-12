#include "Dog.hpp"

Dog::Dog()
{
	type_ = "Dog";
	std::cout << "Dog is created" << std::endl;
}

Dog::Dog(const Dog &other)
{
	*this = other;
	std::cout << "Dog is created as a copy of " << other.type_ << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
		type_ = other.type_;
	std::cout << "Dog is reassigned by " << other.type_ << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog is destroyed" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Dog: Werwerwerr" << std::endl;
}
