#include "Fixed.hpp"

Fixed::Fixed() : raw_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &dec)
{
	std::cout << "Int constructor called" << std::endl;
	// // Overflow control:
	// if (dec > std::numeric_limits<int>::max() >> fractionalBits_
	// 	|| dec < std::numeric_limits<int>::min() >> fractionalBits_) {
	// 	std::cout << "Integer overflow encountered" << std::endl;
	// 	raw_ = 0;
	// 	return ;
	// }
	raw_ = dec << fractionalBits_;
}

Fixed::Fixed(const float &decf)
{
	std::cout << "Float constructor called" << std::endl;
	// // Overflow control:
	// if (decf > std::numeric_limits<int>::max() / (1 << fractionalBits_)
	// 	|| decf < std::numeric_limits<int>::min() / (1 << fractionalBits_)) {
	// 	std::cout << "Float overflow encountered" << std::endl;
	// 	raw_ = 0;
	// 	return ;
	// }
	raw_ = static_cast<int>(roundf(decf * (1 << fractionalBits_)));
}

Fixed::Fixed(const Fixed &other) : raw_(other.raw_)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		raw_ = other.raw_;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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
	return raw_ >> fractionalBits_;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(raw_) / (1 << fractionalBits_);
}

std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed)
{
	outstream << fixed.toFloat();
	return outstream;
}
