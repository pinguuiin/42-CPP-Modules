#include "ScalarConverter.hpp"
#include <cstdlib>  // strtod()
#include <climits> // CHAR_MIN, CHAR_MAX
#include <cmath>  // HUGE_VAL
#include <iomanip>  // fixed and setprecision()
#include <string_view>  // string_view()

ScalarConverter::LiteralType	ScalarConverter::detectType(const std::string &literal)
{
	// INVALID: Empty string
	if (literal.length() == 0)
		return INVALID;
	// CHAR: with single quotes 'c', or a single character c
	if ( (literal.length() == 3 && literal[0] == '\'' && isprint(static_cast<unsigned char>(literal[1]))
		&& literal[2] == '\'') || (literal.length() == 1 && !isdigit(static_cast<unsigned char>(literal[0]))) )
		return CHAR;
	// PSEUDO: pseudo-literals
	if (literal == "-inff" || literal == "+inff" || literal == "nanf"
		|| literal == "-inf" || literal == "+inf" || literal == "nan")
		return PSEUDO;

	// Digital value
	// INT: digits only (with optional sign)
	// FLOAT: with one '.' and a trailing 'f'
	// DOUBLE: with one '.' and no 'f'
	size_t i = 0;
	int hasDot = 0;

	if (literal[0] == '+' || literal[0] == '-')
		++i;
	// start with an 'f' or has only a '.'
	if (literal[i] == 'f' || (literal[i] == '.' && i == literal.length() - 1))
		return INVALID;
	for (; i < literal.length(); ++i) {
		if (isdigit(static_cast<unsigned char>(literal[i])))
			continue;
		if (literal[i] == '.') {
			if (hasDot >= 1)
				return INVALID;
			++hasDot;
			continue;
		}
		// end with 'f'
		if (i == literal.length() - 1 && literal[i] == 'f')
			return FLOAT;
		// has other-than-allowed characters
		return INVALID;
	}
	// no decimal -> integer
	if (hasDot == 0)
		return INT;
	// has decimals, not ending with 'f' -> double
	return DOUBLE;
}

double	ScalarConverter::detectValue(const std::string &literal, LiteralType type)
{
	// 'c' or c
	if (type == CHAR) {
		if (literal.length() == 1)
			return static_cast<double>(literal[0]);
		return static_cast<double>(literal[1]);
	}
	// value = 0.0 for pseudo-literals
	if (type == PSEUDO)
		return 0.0;
	// numeric value
	return strtod(literal.c_str(), NULL);
}

void	ScalarConverter::printChar(double value, LiteralType type)
{
	std::cout << "char: ";
	if (type == CHAR)
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else if (type == PSEUDO)
		std::cout << "impossible" << std::endl;
	else {
		int	num = static_cast<int>(value);
		if (num < CHAR_MIN || num > CHAR_MAX)
			std::cout << "impossible" << std::endl;
		else if (!isprint(static_cast<unsigned char>(value)))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	}
}

void	ScalarConverter::printInt(double value, LiteralType type)
{
	std::cout << "int: ";
	if (type == CHAR)
		std::cout << static_cast<int>(value) << std::endl;
	else if (type == PSEUDO)
		std::cout << "impossible" << std::endl;
	else {
		if (value == HUGE_VAL || value == -HUGE_VAL || value < INT_MIN || value > INT_MAX)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(value) << std::endl;
	}
}

void	ScalarConverter::printFloat(double value, LiteralType type, const std::string &literal)
{
	std::cout << "float: ";
	if (type == CHAR)
		std::cout << std::fixed << std::setprecision(1)
				  << static_cast<float>(value) << "f" << std::endl;
	else if (type == PSEUDO) {
		if (literal == "-inf" || literal == "+inf" || literal == "nan")
			std::cout << literal << "f" << std::endl;
		else
			std::cout << literal << std::endl;
	}
	else {
		if (value == HUGE_VAL || value == -HUGE_VAL)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<float>(value) << "f" << std::endl;
	}
}

void	ScalarConverter::printDouble(double value, LiteralType type, const std::string &literal)
{
	std::cout << "double: ";
	if (type == CHAR)
		std::cout << std::fixed << std::setprecision(1)
				  << value << std::endl;
	else if (type == PSEUDO) {
		if (literal == "-inf" || literal == "+inf" || literal == "nan")
			std::cout << literal << std::endl;
		else
			std::cout << std::string_view(literal).substr(0, literal.length() - 1) << std::endl;
	}
	else {
		if (value == HUGE_VAL || value == -HUGE_VAL)
			std::cout << "impossible" << std::endl;
		else
			std::cout << value << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &literal)
{
	LiteralType	type = detectType(literal);

	if (type == INVALID) {
		std::cout << "Type conversion is impossible for invalid inputs." << std::endl;
		return;
	}

	double	value = detectValue(literal, type);

	printChar(value, type);
	printInt(value, type);
	printFloat(value, type, literal);
	printDouble(value, type, literal);
}
