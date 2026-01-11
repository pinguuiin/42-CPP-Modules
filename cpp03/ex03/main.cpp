#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap a("McDonald");
	ScavTrap b("Hesburger");
	FragTrap c("KFC");
	DiamondTrap d("BurgerKing");

	std::cout << "\nBurgerKing - HP:100 EP:50 AT:30" << std::endl;

	a.attack("BurgerKing");
	b.attack("BurgerKing");
	c.attack("BurgerKing");
	d.takeDamage(50);
	d.beRepaired(40);

	std::cout << "\n=Attack message inherited from ScavTrap "
			  << "but using the attributes from DiamondTrap="
			  << std::endl;
	for (int i = 0; i < 101; ++i) {
		d.attack("air");
	}
	std::cout << std::endl;

	d.whoAmI();
	d.guardGate();
	d.highFivesGuys();
	std::cout << std::endl;

	return 0;
}
