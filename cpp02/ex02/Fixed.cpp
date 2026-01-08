#include "Fixed.hpp"

//==================== Constructors and destructor ====================//

Fixed::Fixed() : raw_(0) {}

Fixed::Fixed(const int &dec)
{
	raw_ = dec << fractionalBits_;
}

Fixed::Fixed(const float &decf)
{
	raw_ = static_cast<int>(roundf(decf * (1 << fractionalBits_)));
}

Fixed::Fixed(const Fixed &other) : raw_(other.raw_) {}

Fixed::~Fixed() {}

//=================== Assignment operators overload ===================//

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		raw_ = other.raw_;
	return *this;
}

Fixed	&Fixed::operator++()
{
	++raw_;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	++raw_;
	return temp;
}

Fixed	&Fixed::operator--()
{
	--raw_;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	--raw_;
	return temp;
}

//=================== Arithmetic operators overload ===================//

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed sum;
	sum.raw_ = raw_ + other.raw_;
	return sum;
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed diff;
	diff.raw_ = raw_ - other.raw_;
	return diff;
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed product;

	product.raw_ = static_cast<int>(static_cast<long long>(raw_) * other.raw_ >> fractionalBits_);
	return product;
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed quotient;

	quotient.raw_ = static_cast<int>(static_cast<long long>(raw_ << fractionalBits_) / other.raw_);
	return quotient;
}

//=================== Comparison operators overload ===================//

bool	Fixed::operator>(const Fixed &other) const
{
	return raw_ > other.raw_;
}

bool	Fixed::operator<(const Fixed &other) const
{
	return raw_ < other.raw_;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return raw_ >= other.raw_;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return raw_ <= other.raw_;
}

bool	Fixed::operator==(const Fixed &other) const
{
	return raw_ == other.raw_;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return raw_ != other.raw_;
}

//=================== Comparison functions overload ===================//

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 <= fixed2) ? fixed1 : fixed2;
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1 <= fixed2) ? fixed1 : fixed2;
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 >= fixed2) ? fixed1 : fixed2;
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1 >= fixed2) ? fixed1 : fixed2;
}

//================ Getter, setter and type conversions ================//

int	Fixed::getRawBits(void) const
{
	return raw_;
}

void	Fixed::setRawBits(int const raw)
{
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


//==================== Insertion operator overload ====================//

std::ostream	&operator<<(std::ostream &outstream, const Fixed &fixed)
{
	outstream << fixed.toFloat();
	return outstream;
}
