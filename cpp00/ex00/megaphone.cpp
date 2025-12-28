#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < argc; ++i) {
			std::string token = argv[i];
			for (int j = 0; token[j]; ++j) {
				unsigned char c = std::toupper(token[j]);
				std::cout << c;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
