#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
	std::cout << "Default constructor called for FragTrap " << name_ << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
	std::cout << "Parameter constructor called for FragTrap " << name_ << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called to copy from FragTrap " << other.name_
			  << std::endl;
	if (this != &other)
		*this = other;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Copy assignment operator called to copy from FragTrap "
			  << other.name_ << std::endl;
	if (this != &other) {
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called to destroy FragTrap " << name_ << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << name_ << " says HighhFiveeeGUUUUUUUYYYYSSSSSS ;D" << std::endl;
}
