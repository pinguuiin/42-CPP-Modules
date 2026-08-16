#pragma once

#include <vector>
#include <deque>

class PmergeMe {

	public:
		PmergeMe() = default;
		PmergeMe(const PmergeMe &o) = default;
		PmergeMe &operator=(const PmergeMe &o) = default;
		~PmergeMe() = default;

		void sort(std::vector<int> &seq);
		void message(const std::vector<int> &seq);

	private:
		std::vector<std::vector<int>> _vec;
		std::deque<std::deque<int>> _deq;
};
