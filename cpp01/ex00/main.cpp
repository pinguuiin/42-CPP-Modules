#include "Zombie.hpp"

/* Zombies are allocated on heap memory in newZombie and on
stack memory in randomChump. Due to the execution order and
usage scope, zombies in randomChump will be destroyed first
followed by zombies created in newZombie*/
int	main()
{
	// ============ Heap allocation =============
	Zombie* x = newZombie("Rabies One");
	Zombie* y = newZombie("Rabies Two");
	Zombie* z = newZombie("Rabies Three");
	x->announce();
	y->announce();
	z->announce();
	std::cout << "\n";

	// ============ Stack allocation ============
	randomChump("Plague I");
	randomChump("Plague II");
	randomChump("Plague III");
	std::cout << "\n";

	delete x;
	delete y;
	delete z;

	return 0;
}