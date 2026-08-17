#include "PmergeMe.hpp"

// ============= Parsing ==============

void PmergeMe::parse(int argc, char **argv)
{
	for (int i = 0; i < argc - 1; ++i) {
		if (argv[i] == nullptr || std::string(argv[i]) == "")
			throw std::invalid_argument("Error");
		int j = 0;
		while (argv[i][j]) {
			if (!std::isdigit(static_cast<unsigned char>(argv[i][j])))
				throw std::invalid_argument("Error");
			++j;
		}
		int num;
		try {
			num = std::stoi(argv[i]);
		}
		catch (const std::out_of_range &e) {
			throw std::out_of_range("Error");
		}
		_vec.push_back(num);
		_deq.push_back(num);
	}
	if (_vec.empty() || _deq.empty())
		throw std::invalid_argument("Error");

	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}

// ============ Ford-Johnson Sort ==============

// merge insert 2 or 3 elements
void mergeInsertBase(std::vector<int> &seq, const std::vector<std::vector<int>> &pairs)
{
	seq.push_back(pairs[0][1]);
	std::swap(seq[0], seq[1]);
	if (pairs.size() == 2) {
		seq.push_back(pairs[1][0]);
		if (seq[2] < seq[1]) {
			std::swap(seq[1], seq[2]);
			if (seq[1] < seq[0])
				std::swap(seq[0], seq[1]);
		}
	}
}

void mergeInsertBase(std::deque<int> &seq, const std::deque<std::deque<int>> &pairs)
{
	seq.push_back(pairs[0][1]);
	std::swap(seq[0], seq[1]);
	if (pairs.size() == 2) {
		seq.push_back(pairs[1][0]);
		if (seq[2] < seq[1]) {
			std::swap(seq[1], seq[2]);
			if (seq[1] < seq[0])
				std::swap(seq[0], seq[1]);
		}
	}
}

size_t getSmallPairIndex(int value, const std::vector<std::vector<int>> &pairs, std::vector<bool> &used)
{
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i][0] == value && pairs[i].size() == 2 && used[i] == false) {
			used[i] = true;
			return i;
		}
	}
	throw std::runtime_error("Error: pair not found");
}

size_t getSmallPairIndex(int value, const std::deque<std::deque<int>> &pairs, std::deque<bool> &used)
{
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i][0] == value && pairs[i].size() == 2 && used[i] == false) {
			used[i] = true;
			return i;
		}
	}
	throw std::runtime_error("Error: pair not found");
}

// The main chain now: b1, a1, a2, a3, ... , am
// The pending elements: b2, b3, b4, ... , bm (m <= 1500)
// The range of elements to be compared with is [2, m]
// so we use the jacobsthal numbers 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, ... , m (capped)
// The insert order should be: 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, ...
std::vector<size_t> getJacobsthalInsertOrder(size_t pendSize)
{
	// generate jacobsthal sequence
	std::vector<int> jacobs;

	size_t a = 0;
	size_t b = 1;
	while (1) {
		size_t c = b + 2 * a;
		a = b;
		b = c;
		if (b >= pendSize)
			break;
		jacobs.push_back(b);
	}
	jacobs.push_back(pendSize);

	// calculate insert order based on jacobsthal group sizes
	std::vector<size_t> order(pendSize - 1);

	std::iota(order.begin(), order.end(), 2);
	for (size_t i = 1; i < jacobs.size(); ++i)
		std::reverse(order.begin() + (jacobs[i - 1] + 1) - 2, order.begin() + jacobs[i] - 2 + 1);
	return order;
}

std::vector<int>::const_iterator binarySearch(int value, const std::vector<int> &seq, size_t high)
{
	size_t low = 0;

	while (low < high) {
		size_t mid = low + (high - low) / 2;
		if (value < seq[mid])
			high = mid;
		else
			low = mid + 1;
	}
	return seq.begin() + low;
}

std::deque<int>::const_iterator binarySearch(int value, const std::deque<int> &seq, size_t high)
{
	size_t low = 0;

	while (low < high) {
		size_t mid = low + (high - low) / 2;
		if (value < seq[mid])
			high = mid;
		else
			low = mid + 1;
	}
	return seq.begin() + low;
}

void PmergeMe::sort(std::vector<int> &seq)
{
	if (seq.size() <= 1)
		return;

	std::vector<std::vector<int>> pairs;

	// merge them into 2-element pairs, and put large number first in each pair
	for (size_t i = 0; i < seq.size() / 2; ++i) {
		pairs.push_back({seq[i * 2], seq[i * 2 + 1]});
		if (pairs[i][0] < pairs[i][1])
			std::swap(pairs[i][0], pairs[i][1]);
	}
	if (seq.size() % 2 == 1)
		pairs.push_back({seq.back()});

	// create large number group
	std::vector<int> large;

	for (const auto &pair : pairs) {
		if (pair.size() == 2)
			large.push_back(pair[0]);
	}

	// recursively pair and select the large number group
	sort(large);
	seq = large;

	// sort the base sequence using merge sort
	if (seq.size() == 1) {
		mergeInsertBase(seq, pairs);
		return;
	}

	// for > 3 elements, insert first small pair to the front of the sequence first
	// `used` flag is to control that small numbers can only be inserted once each
	std::vector<bool> used(pairs.size(), false);

	size_t sid = getSmallPairIndex(seq[0], pairs, used);
	seq.insert(seq.begin(), pairs[sid][1]);

	// insert pending elements in the order derived from jacobsthal numbers
	std::vector<size_t> order = getJacobsthalInsertOrder(large.size());

	// find the insertion position for the small number using binary search, with its large pair as the search bound
	for (size_t i = 0; i < order.size(); ++i) {
		int small = pairs[getSmallPairIndex(large[order[i] - 1], pairs, used)][1];
		auto bound = std::find(seq.begin(), seq.end(), large[order[i] - 1]);
		auto pos = binarySearch(small, seq, bound - seq.begin());

		seq.insert(pos, small);
	}
	// insert the unpaired element if exists
	auto last = pairs.back();
	if (last.size() == 1) {
		seq.insert(binarySearch(last[0], seq, seq.end() - seq.begin()), last[0]);
	}
}

void PmergeMe::sort(std::deque<int> &seq)
{
	if (seq.size() <= 1)
		return;

	std::deque<std::deque<int>> pairs;

	// merge them into 2-element pairs, and put large number first in each pair
	for (size_t i = 0; i < seq.size() / 2; ++i) {
		pairs.push_back({seq[i * 2], seq[i * 2 + 1]});
		if (pairs[i][0] < pairs[i][1])
			std::swap(pairs[i][0], pairs[i][1]);
	}
	if (seq.size() % 2 == 1)
		pairs.push_back({seq.back()});

	// create large number group
	std::deque<int> large;

	for (const auto &pair : pairs) {
		if (pair.size() == 2)
			large.push_back(pair[0]);
	}

	// recursively pair and select the large number group
	sort(large);
	seq = large;

	// sort the base sequence using merge sort
	if (seq.size() == 1) {
		mergeInsertBase(seq, pairs);
		return;
	}

	// for > 3 elements, insert first small pair to the front of the sequence first
	// `used` flag is to control that small numbers can only be inserted once each
	std::deque<bool> used(pairs.size(), false);

	size_t sid = getSmallPairIndex(seq[0], pairs, used);
	seq.insert(seq.begin(), pairs[sid][1]);

	// insert pending elements in the order derived from jacobsthal numbers
	std::vector<size_t> order = getJacobsthalInsertOrder(large.size());

	// find the insertion position for the small number using binary search, with its large pair as the search bound
	for (size_t i = 0; i < order.size(); ++i) {
		int small = pairs[getSmallPairIndex(large[order[i] - 1], pairs, used)][1];
		auto bound = std::find(seq.begin(), seq.end(), large[order[i] - 1]);
		auto pos = binarySearch(small, seq, bound - seq.begin());

		seq.insert(pos, small);
	}
	// insert the unpaired element if exists
	auto last = pairs.back();
	if (last.size() == 1) {
		seq.insert(binarySearch(last[0], seq, seq.end() - seq.begin()), last[0]);
	}
}

void PmergeMe::message() const
{
	std::cout << "After:  ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5)
			  << "Time to process a range of " << _vec.size() << " elements with std::vector : "
			  << _vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : "
			  << _deqTime << " us" << std::endl;
}

void PmergeMe::run()
{
	// Vector
	auto start = std::chrono::steady_clock::now();
	sort(_vec);
	auto end = std::chrono::steady_clock::now();
	_vecTime = std::chrono::duration<double, std::micro>(end - start).count();

	// Deque
	start = std::chrono::steady_clock::now();
	sort(_deq);
	end = std::chrono::steady_clock::now();
	_deqTime = std::chrono::duration<double, std::micro>(end - start).count();

	message();
}
