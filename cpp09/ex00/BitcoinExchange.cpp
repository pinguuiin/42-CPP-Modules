#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

std::string &trim(std::string &s)
{
	const char *whitespace = " \n\r\t\f\v";

	size_t start = s.find_first_not_of(whitespace);
	s = (start == std::string::npos) ? "" : s.substr(start);

	size_t end = s.find_last_not_of(whitespace);
	s = (end == std::string::npos) ? "" : s.substr(0, end + 1);

	return s;
}

bool isValidDate(std::string &s)
{
	trim(s);
	// valid format: YYYY-MM-DD
	if (s.empty() || s.length() != 10)
		return false;
	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7) {
			if (s[i] != '-')
				return false;
		}
		else {
			if (!std::isdigit(s[i]))
				return false;
		}
	}
	// valid range
	// int year = std::stoi(s.substr(0, 4));
	int month = std::stoi(s.substr(5, 2));
	int day = std::stoi(s.substr(8, 2));

	// if (year < 2009 || s == "2009-01-01")
	// 	return false;
	if (month < 1 || month > 12)
		return false;
	// doesn't take leap year into consideration
	const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

// a valid number. doesn't control range
bool isValidValue(std::string &s)
{
	trim(s);
	if (s.empty())
		return false;

	int hasDot = 0;
	int hasValue = 0;
	unsigned int i = 0;

	if (s[i] == '-' || s[i] == '+')
		++i;
	for (; i < s.length(); ++i) {
		if (s[i] == '.') {
			if (hasDot >= 1)
				return false;
			++hasDot;
			continue;
		}
		if (!std::isdigit(s[i]))
			return false;
		++hasValue;
	}
	if (hasValue == 0)
		return false;
	return true;
}

void BitcoinExchange::handleRateLine(std::string &line)
{
	std::istringstream iss(line);
	std::string dateStr = "";
	std::string valueStr = "";

	std::getline(iss, dateStr, ',');
	std::getline(iss, valueStr);

	if (!isValidDate(dateStr) || !isValidValue(valueStr))
		return;

	float fvalue = std::stof(valueStr);
	_rates.insert({dateStr, fvalue});  // date, exchange rate
}

void BitcoinExchange::loadRates(const std::string &path)
{
	// Open the file
	std::ifstream infile(path);

	if (!infile.is_open())
		throw std::runtime_error("Error: unable to open the rate file");

	// Read the file line by line, excluding the first line if it's a header
	std::string line  = "";

	std::getline(infile, line);
	if (!line.empty() && line != "date,exchange_rate")
		handleRateLine(line);
	while (std::getline(infile, line)) {
		if (!line.empty())
			handleRateLine(line);
	}
}

void BitcoinExchange::handleEventLine(std::string &line)
{
	std::istringstream iss(line);
	std::string dateStr = "";
	std::string valueStr = "";

	std::getline(iss, dateStr, '|');
	std::getline(iss, valueStr);

	try {
		if (!isValidDate(dateStr) || !isValidValue(valueStr))
			throw std::invalid_argument("Error: bad input => " + line);

		float fvalue = std::stof(valueStr);
		if (fvalue < 0)
			throw std::out_of_range("Error: not a positive number");
		if (fvalue > 1000)
			throw std::out_of_range("Error: too large a number");

		std::map<std::string, float>::const_iterator it = _rates.upper_bound(dateStr);
		if (it == _rates.begin())
			throw std::out_of_range("Error: date too old");
		--it;
		std::cout << dateStr << " => " << fvalue << " = " << it->second * fvalue
				  << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void BitcoinExchange::loadEvents(std::string &path)
{
	// Open the file
	std::ifstream infile(trim(path));

	if (!infile.is_open())
		throw std::runtime_error("Error: unable to open the input file");

	// Read the file line by line
	std::string line  = "";

	std::getline(infile, line);
	if (line.empty() || line != "date | value")
		std::cerr << "Error: invalid input file header" << std::endl;
	while (std::getline(infile, line)) {
		if (!line.empty())
			handleEventLine(line);
	}
}


