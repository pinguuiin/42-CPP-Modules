#include "Weapon.hpp"

const std::string	&Weapon::getType() const
{
	return type_;
}

void	Weapon::setType(std::string type)
{
	type_ = type;
}

Weapon::Weapon(std::string type) : type_(type) {};
