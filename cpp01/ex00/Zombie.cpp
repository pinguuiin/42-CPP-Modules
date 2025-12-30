#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : name_(name)
{
	std::cout << "🧟 New Zombie [" << name_ << "] is created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "🌪️ Zombie [" << name_ << "] is destroyed" << std::endl;
}