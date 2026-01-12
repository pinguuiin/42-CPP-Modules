#include "Cat.hpp"

Cat::Cat()
{
	type_ = "Cat";
	std::cout << "Cat is created" << std::endl;
}

Cat::Cat(const Cat &other)
{
	*this = other;
	std::cout << "Cat is created as a copy of " << other.type_ << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
		type_ = other.type_;
	std::cout << "Cat is reassigned by " << other.type_ << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat is destroyed" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat: Mew mew" << std::endl;
}
