#include "Animal.hpp"

Animal::Animal() : type_("Animal")
{
	std::cout << "Animal is created" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal is created as a copy of " << other.type_ << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
		type_ = other.type_;
	std::cout << "Animal is reassigned by " << other.type_ << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal is destroyed" << std::endl;
}

const std::string	&Animal::getType() const
{
	return type_;
}
