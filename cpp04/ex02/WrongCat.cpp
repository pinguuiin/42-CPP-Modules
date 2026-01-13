#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type_ = "WrongCat";
	std::cout << "WrongCat is created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
	std::cout << "WrongCat is created as a copy of " << other.type_ << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		type_ = other.type_;
	std::cout << "WrongCat is reassigned by " << other.type_ << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat is destroyed" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat: Mew mew!" << std::endl;
}
