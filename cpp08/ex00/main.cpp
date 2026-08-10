#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main(void)
{
	std::cout << "========= vector =========" << std::endl;
	std::vector<int> v = {10, 20, 30, 40, 50};

	easytest(v, 20);

	std::cout << "========= not found =========" << std::endl;

	easytest(v, 100);

	std::cout << "========= list / deque =========" << std::endl;
	std::list<int> l = {6, 7, 8, 9, 10};
	std::deque<int> d = {-1, -2, -3, -2, -1};

	easytest(l, 9);
	easytest(d, -2);

	std::cout << "========= const container =========" << std::endl;
	const std::vector<int> cv = {10, 20, 30, 40, 50};

	easytest(cv, 50);

	std::cout << "========= empty container =========" << std::endl;
	std::vector<int> ec;

	easytest(ec, 2);

	return 0;
}
