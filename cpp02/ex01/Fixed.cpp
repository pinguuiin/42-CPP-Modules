#include "Fixed.hpp"

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return raw_;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	raw_ = raw;
}

int	Fixed::toInt(void) const
{
	return roundf(raw_ >> fractionalBits_);
}

float	Fixed::toFloat(void) const
{
	return raw_ >> fractionalBits_;
}

Fixed::Fixed(const int dec)
{
	std::cout << "Int constructor called" << std::endl;
	raw_ =
}

Fixed::Fixed(const float decf)
{
	std::cout << "Float constructor called" << std::endl;
	raw_ =
}

Fixed::Fixed(const Fixed &other) : raw_(other.raw_)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		raw_ = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed)
{
	outstream << fixed.toFloat();
	return outstream;
}