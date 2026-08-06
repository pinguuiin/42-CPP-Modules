#pragma once

#include <iostream>
#include <cstddef>	// size_t

template <typename T>
void print(const T &a)
{
	std::cout << a << std::endl;
}

template <typename T>
void add(T &b)
{
	++b;
}

template <typename T, typename F>
void iter(T *arr, const size_t len, F func)
{
	for (size_t i = 0; i < len; ++i) {
		func(arr[i]);
	}
}
