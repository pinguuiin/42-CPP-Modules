#pragma once

#include <cstddef>  // size_t
#include <exception>

template <typename T>
class Array {

	public:
		Array();
		// explicit: blocks implicit conversion from unsigned int to Array<T>. So `Array<int> a = 5` will throw error.
		explicit Array(unsigned int n);
		Array(const Array &o);
		Array &operator=(const Array &o);
		~Array();

		T &operator[](unsigned int i);
		const T &operator[](unsigned int i) const;

		size_t size() const;

		class OutOfBoundsException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

	private:
		T *_data;
		size_t _size;
};

#include "Array.tpp"
