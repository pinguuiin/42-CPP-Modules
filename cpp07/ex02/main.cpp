#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
	size_t i = 0;

	// empty array -> access its element -> throw
	Array<int> a;
	try {
		std::cout << "a[0] = " << a[0] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Couldn't access the element: " << e.what() << std::endl;
	}

	// non-empty array -> access out-of-bound element -> throw
	Array<int> arr(5);
	try {
		std::cout << "arr[5] = " << arr[5] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Couldn't access the element: " << e.what() << std::endl;
	}

	// default init (all elements = 0) for ctor
	Array<int> b(5);

	for (i = 0; i < b.size(); ++i)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;
	std::cout << "\n";

	// self-assignment
	b = *(&b);

	// copy ctor and change the original's value, the replica won't change
	Array<int> c(3);
	Array<int> d = c;
	Array<int> e(c);

	d[0] = 4;
	e[1] = 2;

	for (i = 0; i < c.size(); ++i)
		std::cout << "c[" << i << "] = " << c[i] << std::endl;
	for (size_t i = 0; i < d.size(); ++i)
		std::cout << "d[" << i << "] = " << d[i] << std::endl;
	for (size_t i = 0; i < e.size(); ++i)
		std::cout << "e[" << i << "] = " << e[i] << std::endl;
	std::cout << "\n";

	// const operator[]
	const Array<int> x(3);

	// this won't work
	// x[1] = 42;

	std::cout << "x[1] = " << x[1] << "\n" << std::endl;

	// string
	Array<std::string> y(3);

	y[0] = "red";
	y[1] = "three";
	y[2] = "meow";

	for (i = 0; i < y.size(); ++i)
		std::cout << "y[" << i << "] = " << y[i] << std::endl;

	return 0;
}
