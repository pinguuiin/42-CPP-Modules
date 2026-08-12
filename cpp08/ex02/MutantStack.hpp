#pragma once

#include <stack>
#include <deque>

// `std::stack` is not a container, it's a container *adaptor*, which are classes that
// use an encapsulated object of a standard container class as its underlying container,
// providing a specific set of member functions to access its elements.
// By default, `std::stack` uses `std::deque` as its underlying container.
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

	public:
		// We need to define the type here because Container is a template parameter,
		// so the compiler can't know on its own that Container::iterator names a type
		// rather than a value.
		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

		MutantStack() = default;
		MutantStack(const MutantStack &o) = default;
		MutantStack &operator=(const MutantStack &o) = default;
		~MutantStack() = default;

		iterator				begin() { return this->c.begin(); }
		iterator				end() { return this->c.end(); }
		const_iterator			begin() const { return this->c.begin(); }
		const_iterator			end() const { return this->c.end(); }

		reverse_iterator		rbegin() { return this->c.rbegin(); }
		reverse_iterator		rend() { return this->c.rend(); }
		const_reverse_iterator	rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator	rend() const { return this->c.rend(); }
};
