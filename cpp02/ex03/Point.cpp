#include "Point.hpp"

Point::Point() : x_(0), y_(0) {}

Point::Point(const float &num1, const float &num2) : x_(Fixed(num1)), y_(Fixed(num2)) {}

Point::Point(const Point &other) : x_(other.x_), y_(other.y_) {}

Point::~Point() {}

const Fixed	&Point::getX() const
{
	return x_;
}

const Fixed	&Point::getY() const
{
	return y_;
}
