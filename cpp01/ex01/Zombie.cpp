#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	name_ = name;
	std::cout << "A Zombie is named [" << name << "]" << std::endl;
}

Zombie::Zombie()
{
	std::cout << "🧟 New Zombie is created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "🌪️ Zombie [" << name_ << "] is destroyed" << std::endl;
}