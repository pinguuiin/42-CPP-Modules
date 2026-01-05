#include "Zombie.hpp"

/* Zombie array is allocated on heap memory */
int	main()
{
	Zombie* z = zombieHorde(6, "Sheep");

	for (int i = 0; i < 6; ++i)
		z[i].announce();
	std::cout << "\n";

	delete[] z;

	return 0;
}
