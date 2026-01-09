#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

typedef struct s_coef {

	Fixed kx;
	Fixed ky;
	Fixed kc;

} t_coef;

class Point {

	public:
		Point();
		Point(const float &num1, const float &num2);
		Point(const Point &other);
		Point &operator=(const Point &other) = delete;
		~Point();

		const Fixed &getX() const;
		const Fixed &getY() const;

	private:
		const Fixed x_;
		const Fixed y_;
};

#endif
