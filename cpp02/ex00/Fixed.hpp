#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	public:
		int getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

	private:
		int raw_;
		static const int fractionalBits_{8};
};

#endif
