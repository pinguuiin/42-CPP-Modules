#include "identify.hpp"
#include <iostream>
#include <cstdlib>  // rand()

Base	*generate(void)
{
	switch (rand() % 3) {
		case 0:
			std::cout << "A is generated" << std::endl;
			return new A();
		case 1:
			std::cout << "B is generated" << std::endl;
			return new B();
		default:
			std::cout << "C is generated" << std::endl;
			return new C();
	}
}

void	identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	if (a != nullptr) {
		std::cout << "A" << std::endl;
		return;
	}

	B *b = dynamic_cast<B *>(p);
	if (b != nullptr) {
		std::cout << "B" << std::endl;
		return;
	}

	C *c = dynamic_cast<C *>(p);
	if (c != nullptr) {
		std::cout << "C" << std::endl;
		return;
	}

	std::cout << "Unknown type" << std::endl;
}

void	identify(Base &p)
{
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &e) {}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &e) {}

	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &e) {}

	std::cout << "Unknown type" << std::endl;
}
