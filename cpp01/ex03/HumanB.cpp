#include "HumanB.hpp"

void	HumanB::attack() const
{
	std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}

HumanB::HumanB(std::string name) : name_(name) {};
