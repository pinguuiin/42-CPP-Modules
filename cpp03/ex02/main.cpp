#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap a("McDonald");
	ScavTrap b("Hesburger");
	FragTrap c("KFC");
	ClapTrap *p = &b;
	std::cout << std::endl;

	c.highFivesGuys();
	b.guardGate();
	b.attack("KFC");
	c.takeDamage(20);
	c.beRepaired(20);
	std::cout << std::endl;

	for (int i = 0; i < 10; ++i) {
		a.attack("Hesburger");
		b.takeDamage(0);
	}
	a.attack("Hesburger");
	std::cout << std::endl;

	for (int i = 0; i < 3; ++i) {
		b.attack("KFC");
		c.takeDamage(20);
	}
	std::cout << std::endl;

	c.attack("McDonald");
	a.takeDamage(30);

	std::cout << "\n===Test copy constructor, e should be a copy of died a===" << std::endl;
	ClapTrap e(a);
	e.beRepaired(10);

	std::cout << "\n===Test if upcasting prints out derived function===" << std::endl;
	p->attack("self");
	std::cout << std::endl;

	return 0;
}
