#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>

int main(void)
{
	// ---------- subject test ----------

	std::cout << "\n========= subject test =========" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;   // 17

	mstack.pop();

	std::cout << mstack.size() << std::endl;   // 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;   // 5, 3, 5, 737, 0
		++it;
	}
	std::stack<int> s(mstack);

	// ---------- same test with std::list ----------

	// The printed output should be the same
	std::cout << "\n========= std::list equivalent =========" << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();

	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	++lit;
	--lit;
	while (lit != lite) {
		std::cout << *lit << std::endl;   // 5, 3, 5, 737, 0
		++lit;
	}

	// ---------- reverse iterators ----------

	std::cout << "\n========= reverse iterators =========" << std::endl;

	MutantStack<int> rstack;

	for (int i = 1; i < 6; ++i)
		rstack.push(i * 5);

	MutantStack<int>::reverse_iterator rit = rstack.rbegin();
	MutantStack<int>::reverse_iterator rite = rstack.rend();

	while (rit != rite) {
		std::cout << *rit << std::endl;  // 25, 20, 15, 10, 5
		++rit;
	}

	// ---------- const_iterator ----------

	std::cout << "\n========= const_iterator =========" << std::endl;

	MutantStack<int> cstack;

	for (int i = 1; i < 6; ++i)
		cstack.push(i * 5);

	const MutantStack<int> &cref = cstack;
	MutantStack<int>::const_iterator cit = cref.begin();
	MutantStack<int>::const_iterator cite = cref.end();

	while (cit != cite) {
		std::cout << *cit << std::endl;  // 5, 10, 15, 20, 25
		++cit;
	}

	return 0;
}
