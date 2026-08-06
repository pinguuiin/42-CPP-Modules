#include "iter.hpp"
#include <string>

int main(void)
{
	int ints[5] = {1, 2, 3, 4, 5};
	const int cints[3] = {1, 10, 100};
	std::string strs[3]	= {"palm", "banana", "coco"};

	// ============ int =============
	std::cout << "int:" << std::endl;

	iter(ints, 5, print<int>);
	std::cout << "\n";
	iter(ints, 5, add<int>);
	iter(ints, 5, print<int>);  // ==> print() takes const by default but can also be instantiated by non-const
	std::cout << "\n";

	// iter(ints, 5, add<const int>);  // ==> add() can only be instantiated by non-const
	iter(ints, 5, print<const int>);
	std::cout << "\n";

	// ========= const int ==========
	std::cout << "const int:" << std::endl;

	// iter(cints, 3, add<int>);  // ==> add() cannot take any const parameter
	iter(cints, 3, print<int>);
	std::cout << "\n";

	// iter(cints, 3, add<const int>);
	iter(cints, 3, print<const int>);
	std::cout << "\n";

	// ========== string ============
	std::cout << "string:" << std::endl;

	iter(strs, 3, print<std::string>);
	std::cout << "\n";

	iter(strs, 3, print<const std::string>);

	return 0;
}
