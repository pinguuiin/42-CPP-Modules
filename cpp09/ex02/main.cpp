#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <cstddef>
#include <limits>
#include <stdexcept>

std::vector<int> parse(int argc, char **argv)
{
	std::vector<int> original;

	for (int i = 0; i < argc - 1; ++i) {
		if (argv[i] == nullptr || std::string(argv[i]) == "")
			throw std::invalid_argument("Error");
		int j = 0;
		while (argv[i][j]) {
			if (!std::isdigit(argv[i][j]))
				throw std::invalid_argument("Error");
			++j;
		}
		int num = std::stoi(argv[i]);
		if (num > std::numeric_limits<int>::max())
			throw std::out_of_range("Error");
		original.push_back(num);
	}
	if (original.empty())
		throw std::invalid_argument("Error");

	std::cout << "Before: ";
	for (size_t i = 0; i < original.size(); ++i)
		std::cout << original[i] << " ";
	std::cout << std::endl;

	return original;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try {
		PmergeMe pm;

		std::vector<int> seq = parse(argc, ++argv);
		pm.sort(seq);
		pm.message(seq);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
