#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	public:
		// Constructors and destructor
		Fixed();
		Fixed(const int &dec);
		Fixed(const float &decf);
		Fixed(const Fixed &other);
		~Fixed();

		// Assignment operators overload
		Fixed &operator=(const Fixed &other);
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		// Arithmetic operators overload
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Comparison operators overload
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Comparison functions overload
		static Fixed &min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed &max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);

		// Getter, setter and type conversions
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;

	private:
		int raw_;
		static const int fractionalBits_{8};
};

// Insertion operator overload
std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed);

#endif
