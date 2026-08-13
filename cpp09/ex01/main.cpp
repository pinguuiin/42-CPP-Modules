#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}
	try {
		RPN rpn;
		rpn.process(argv[1]);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
