#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2) {
		std::cerr << "Please input your complaint level as one argument" << std::endl;
		return 1;
	}
	harl.complain(std::string(argv[1]));
	return 0;
}
