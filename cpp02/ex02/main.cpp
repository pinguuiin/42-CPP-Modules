#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );  // b = 10.10
	Fixed const c( Fixed( 5.0f ) / Fixed( 3 ) );  // c = 1.66
	Fixed const d( Fixed( 10000.6f ) + Fixed( 2345 ) );  // d = 12345.6
	Fixed const e( Fixed( 66666.6f ) - Fixed( 333 ) );  // e = 66333.6


	std::cout << "a: " << a << std::endl;
	std::cout << "a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;  // a = 2 * epsilon

	std::cout << "\nb: " << b << std::endl;
	std::cout << "b: " << ++b << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "b: " << b++ << std::endl;
	std::cout << "b: " << b << std::endl;  // b = 10.10 - 2 * epsilon

	std::cout << "\nb: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;


	std::cout << "\nmax(a,b): " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a,b): " << Fixed::min( a, b ) << std::endl;
	std::cout << "a is equal to b? : " << (a == b ? "✅True" : "❌False") << std::endl;

	return 0;
}
