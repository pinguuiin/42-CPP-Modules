#include "ScavTrap.hpp"

int	main()
{
	ScavTrap a("McDonald");
	ScavTrap b("Hesburger");
	ScavTrap c(a);
	ScavTrap d;
	std::cout << std::endl;

	b.attack("Hesburger");
	b.takeDamage(20);
	b.beRepaired(10);
	std::cout << std::endl;

	for (int i = 0; i < 60; ++i) {
		a.attack("Hesburger");
		b.takeDamage(20);
	}
	std::cout << std::endl;

	b.beRepaired(10);
	std::cout << std::endl;

	return 0;
}
