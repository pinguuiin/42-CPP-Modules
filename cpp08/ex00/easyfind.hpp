#pragma once

#include <iostream>
#include <algorithm>  // find()
#include <iterator>  // distance()

// non-const overload: caller can modify the found element
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	return std::find(container.begin(), container.end(), value);
}

// const overload
template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	return std::find(container.begin(), container.end(), value);
}

// test function for main
template <typename T>
void easytest(T &container, int value)
{
	std::cout << "\nContainer elements:" << std::endl;
	for (auto item : container)
		std::cout << item << std::endl;

	auto it = easyfind(container, value);

	if (it == container.end())
		std::cout << value << " is not found" << std::endl;
	else
		std::cout << value << " is found with an index " << std::distance(container.begin(), it) << std::endl;
	std::cout << std::endl;
}
