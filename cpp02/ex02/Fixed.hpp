#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	public:
		Fixed();
		Fixed(const int &dec);
		Fixed(const float &decf);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;

	private:
		int raw_;
		static const int fractionalBits_{8};
};

std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed);

#endif
