#include "HumanA.hpp"

void	HumanA::attack() const
{
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
