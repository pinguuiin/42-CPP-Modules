#include "HumanA.hpp"

void	HumanA::attack() const
{
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon) {};
