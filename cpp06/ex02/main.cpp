#include "identify.hpp"
#include <iostream>
#include <cstdlib>  // srand()
#include <ctime>  // time()

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < 8; ++i) {
		Base *p = generate();

		std::cout << "ptr: ";
		identify(p);
		std::cout << "ref: ";
		identify(*p);

		delete p;
	}

	return 0;
}
