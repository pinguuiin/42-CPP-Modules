#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange &o) = default;
		BitcoinExchange	&operator=(const BitcoinExchange &o) = default;
		~BitcoinExchange() = default;

		void loadRates(const std::string &path);
		void handleRateLine(std::string &line);

		void loadEvents(std::string &path);
		void handleEventLine(std::string &line);

	private:
		std::map<std::string, float> _rates;
};

