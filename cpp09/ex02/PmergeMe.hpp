#pragma once

#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <numeric> // iota()
#include <iostream>
#include <chrono>
#include <iomanip>

class PmergeMe {

	public:
		PmergeMe() = default;
		PmergeMe(const PmergeMe &o) = default;
		PmergeMe &operator=(const PmergeMe &o) = default;
		~PmergeMe() = default;

		void parse(int argc, char **argv);
		void run();
		void sort(std::vector<int> &seq);
		void sort(std::deque<int> &seq);
		void message() const;

	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		double _vecTime{0};
		double _deqTime{0};
};
