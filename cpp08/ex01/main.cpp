#include "Span.hpp"
#include <iostream>
#include <climits>  // INT_MIN, INT_MAX

int main(void)
{
	// ========== subject example ==========

	std::cout << "=== subject example ===" << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;  // 2
	std::cout << sp.longestSpan() << std::endl;   // 14

	// ========== too few elements ==========

	std::cout << "\n=== too few elements ===" << std::endl;

	Span empty(5);
	try { empty.longestSpan(); }
	catch (const std::exception &e) { std::cout << "Empty: " << e.what() << std::endl; }

	Span one(5);
	one.addNumber(42);
	try { one.shortestSpan(); }
	catch (const std::exception &e) { std::cout << "Single element: " << e.what() << std::endl; }

	// ========== capacity ==========

	std::cout << "\n=== capacity ===" << std::endl;

	Span small(3);
	small.addNumber(1);
	small.addNumber(2);
	small.addNumber(3);
	try { small.addNumber(4); }
	catch (const std::exception &e) { std::cout << "Full: " << e.what() << std::endl; }
	std::cout << "Still usable:\n" << small.shortestSpan()
			  << "\n" << small.longestSpan() << std::endl;  // 1, 2

	Span zero(0);
	try { zero.addNumber(1); }
	catch (const std::exception &e) { std::cout << "Capacity 0: " << e.what() << std::endl; }

	// ========== values ==========

	std::cout << "\n=== values ===" << std::endl;

	Span dup(4);
	dup.addNumber(5);
	dup.addNumber(5);
	dup.addNumber(9);
	dup.addNumber(5);
	std::cout << "duplicates:\n" << dup.shortestSpan()
			  << "\n" << dup.longestSpan() << std::endl;  // 0, 4

	Span neg(3);
	neg.addNumber(-5);
	neg.addNumber(0);
	neg.addNumber(5);
	std::cout << "crossing zero:\n" << neg.shortestSpan()
			  << "\n" << neg.longestSpan() << std::endl;  // 5, 10

	Span lim(4);
	lim.addNumber(INT_MAX);
	lim.addNumber(INT_MAX - 1);
	lim.addNumber(INT_MIN);
	lim.addNumber(INT_MIN + 1);
	std::cout << "int extremes:\n" << lim.shortestSpan()
			  << "\n" << lim.longestSpan() << std::endl;  // 1, 4294967295

	// ========== addRange ==========

	std::cout << "\n=== addRange ===" << std::endl;

	std::vector<int> src;
	for (size_t i = 0; i < 10001; ++i)
		src.push_back(i * 5);

	Span dest(10001);
	dest.addRange(src.begin(), src.end());
	std::cout << "10000 numbers:\n" << dest.shortestSpan()
			  << "\n" << dest.longestSpan() << std::endl;  // 5, 50000

	return 0;
}
