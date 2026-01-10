#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("McDonald");
	ClapTrap b("Hesburger");
	ClapTrap c(a);
	ClapTrap d;

	b.attack("Hesburger");
	b.takeDamage(0);
	b.beRepaired(10);
	std::cout << std::endl;

	for (int i = 0; i < 12; ++i) {
		a.attack("Hesburger");
		b.takeDamage(2);
	}
	std::cout << std::endl;

	b.beRepaired(10);
	std::cout << std::endl;

	return 0;
}
