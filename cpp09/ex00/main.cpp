#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Invalid input. Usage: ./btc <input file>" << std::endl;
		return 1;
	}

	BitcoinExchange btc;

	try {
		std::string eventFile(argv[1]);

		btc.loadRates("data.csv");
		btc.loadEvents(eventFile);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
