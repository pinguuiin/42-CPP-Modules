#include "Zombie.hpp"

/* Zombies are allocated on heap memory in newZombie and on
stack memory in randomChump. Due to the execution order and
usage scope, zombies in randomChump will be destroyed first
followed by zombies created in newZombie*/
int	main()
{
	// ============ Heap allocation =============
	Zombie* z = zombieHorde(6, "Sheep");

	for (int i = 0; i < 6; ++i)
		z[i].announce();
	std::cout << "\n";

	delete[] z;

	return 0;
}