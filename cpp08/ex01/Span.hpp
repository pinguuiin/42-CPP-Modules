#pragma once

#include <vector>
#include <cstddef>  // size_t
#include <stdexcept>
#include <algorithm>

class Span {

	public:
		Span() = delete;
		explicit Span(unsigned int N);
		Span(const Span &o);
		Span &operator=(const Span &o);
		~Span();

		void addNumber(int value);
		unsigned int shortestSpan();
		unsigned int longestSpan() const;

		template <typename T>
		void addRange(T begin, T end) {
			while (begin != end) {
				addNumber(*begin);
				++begin;
			}
		}

	private:
		unsigned int _capacity;
		unsigned int _size;
		std::vector<int> _data;
};
