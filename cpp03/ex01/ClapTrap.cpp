#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("Unknown")
{
	std::cout << "Default constructor called for ClapTrap " << name_ << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name)
{
	std::cout << "Parameter constructor called for ClapTrap " << name_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called to copy from ClapTrap " << other.name_ << std::endl;
	if (this != &other)
		*this = other;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called to copy from ClapTrap "
			  << other.name_ << std::endl;
	if (this != &other) {
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called to destroy ClapTrap " << name_ << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (hitPoints_ == 0 || energyPoints_ == 0) {
		std::cout << "ClapTrap " << name_ << " has no HP or EP to attack"
				  << std::endl;
		return ;
	}
	--energyPoints_;
	std::cout << ("ClapTrap " + name_ + " attacks " + target + ", causing ")
			  << attackDamage_ << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints_ == 0) {
		std::cout << "ClapTrap " << name_ << " is already dead!" << std::endl;
		return ;
	}
	if (amount > hitPoints_)
		amount = hitPoints_;
	hitPoints_ -= amount;
	std::cout << "ClapTrap " << name_ << " is attacked, " << amount << " HP is lost!"
			  << std::endl;
	if (hitPoints_ == 0)
		std::cout << "ClapTrap " << name_ << " died!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints_ == 0 || energyPoints_ == 0) {
		std::cout << "ClapTrap " << name_ << " has no HP or EP to repair"
				  << std::endl;
		return ;
	}
	hitPoints_ += amount;
	std::cout << "ClapTrap " << name_ << " regained " << amount << " HP, now have "
			  << hitPoints_ << " HP left!" << std::endl;
}

