#include "HumanB.hpp"

void	HumanB::attack() const
{
	if (weapon_)
		std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
	else
		std::cout << name_ << " is unarmed" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}

HumanB::HumanB(std::string name) : name_(name), weapon_(nullptr) {};
