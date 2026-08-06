#include "operation.hpp"
#include <iostream>
#include <string>

int main(void)
{
	// default test
	std::cout << "========= subject test =========" << std::endl;
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	// other types
	std::cout << "\n========= other types =========" << std::endl;
	char e = 'a';
	char f = 'b';

	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
	std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;

	double g = -42.2;
	double h = 5.5;

	::swap(g, h);
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min(g, h) << std::endl;
	std::cout << "max( g, h ) = " << ::max(g, h) << std::endl;

	bool i = true;
	bool j = false;

	::swap(i, j);
	std::cout << "i = " << i << ", j = " << j << std::endl;
	std::cout << "min( i, j ) = " << ::min(i, j) << std::endl;
	std::cout << "max( i, j ) = " << ::max(i, j) << std::endl;

	const int k = 10;
	const int l = 30;

	std::cout << "k = " << k << ", l = " << l << std::endl;
	std::cout << "min( k, l ) = " << ::min(k, l) << std::endl;
	std::cout << "max( k, l ) = " << ::max(k, l) << std::endl;

	// equal values - return the second one
	std::cout << "\n========= equal values =========" << std::endl;
	int m = 7;
	int n = 7;

	std::cout << "min( m, n ) is n? "
			  << (&::min(m, n) == &n ? "yes" : "no") << std::endl;
	std::cout << "max( m, n ) is n? "
			  << (&::max(m, n) == &n ? "yes" : "no") << std::endl;

	return 0;
}
