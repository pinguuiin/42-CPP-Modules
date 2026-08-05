#pragma once

#include <iostream>
#include <string>

class ScalarConverter {

	public:
		static void convert(const std::string &literal);

	private:
		// Not instantiable; ctor/dtor not applicable
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &o) = delete;
		ScalarConverter &operator=(const ScalarConverter &o) = delete;
		~ScalarConverter() = delete;

		enum LiteralType {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO,
			INVALID
		};

		static LiteralType detectType(const std::string &literal);
		static double detectValue(const std::string &literal, LiteralType type);

		static void printChar(double value, LiteralType type);
		static void printInt(double value, LiteralType type);
		static void printFloat(double value, LiteralType type, const std::string &literal);
		static void printDouble(double value, LiteralType type, const std::string &literal);
};
