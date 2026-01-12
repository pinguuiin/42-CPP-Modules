#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unknown_clap_name")
{
	name_ = "Unknown";
	hitPoints_ = FragTrap::hitPoints_;
	energyPoints_ = ScavTrap::energyPoints_;
	attackDamage_ = FragTrap::attackDamage_;
	std::cout << "Default constructor called for DiamondTrap " << name_ << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	name_ = name;
	hitPoints_ = FragTrap::hitPoints_;
	energyPoints_ = ScavTrap::energyPoints_;
	attackDamage_ = FragTrap::attackDamage_;
	std::cout << "Parameter constructor called for DiamondTrap " << name_ << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.name_ + "_clap_name")
{
	std::cout << "Copy constructor called to copy from DiamondTrap " << other.name_
			  << std::endl;
	if (this != &other)
		*this = other;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "Copy assignment operator called to copy from DiamondTrap "
			  << other.name_ << std::endl;
	if (this != &other) {
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called to destroy DiamondTrap " << name_ << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}


void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << name_ << std::endl;
	std::cout << "My grandparent is " << ClapTrap::name_ << std::endl;
}
