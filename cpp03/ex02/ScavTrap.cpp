#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	std::cout << "Default constructor called for ScavTrap " << name_ << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	std::cout << "Parameter constructor called for ScavTrap " << name_ << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Copy constructor called to copy from ScavTrap " << other.name_
			  << std::endl;
	if (this != &other)
		*this = other;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Copy assignment operator called to copy from ScavTrap "
			  << other.name_ << std::endl;
	if (this != &other) {
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called to destroy ScavTrap " << name_ << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (hitPoints_ == 0 || energyPoints_ == 0) {
		std::cout << "ScavTrap " << name_ << " is too weak to attack"
				  << std::endl;
		return ;
	}
	--energyPoints_;
	std::cout << ("ScavTrap " + name_ + " attacks " + target + ", causing ")
			  << attackDamage_ << " points of physical damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name_ << " now in Gate keeper mode" << std::endl;
}
