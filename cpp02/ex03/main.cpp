#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

static void	test(const std::string& name, bool result, bool expected)
{
	std::cout << name << " : ";
	if (result == expected)
		std::cout << "✅ OK";
	else
		std::cout << "❌ FAIL";
	std::cout << std::endl;
}

int	main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	// 1. Point strictly inside
	test(
		"Inside (5,5)",
		bsp(a, b, c, Point(3, 3)),
		true
	);

	// 2. Point clearly outside
	test(
		"Outside (10,10)",
		bsp(a, b, c, Point(10, 10)),
		false
	);

	// 3. Point on hypotenuse (edge)
	test(
		"On edge (5,5)",
		bsp(a, b, c, Point(5, 5)),
		false
	);

	// 4. Point on vertex A
	test(
		"On vertex A",
		bsp(a, b, c, Point(0, 0)),
		false
	);

	// 5. Point just outside near edge
	test(
		"Near outside (6,4)",
		bsp(a, b, c, Point(6, 4)),
		false
	);

	// 6. Same triangle but reversed order (orientation test)
	test(
		"Inside with reversed triangle",
		bsp(a, c, b, Point(3, 3)),
		true
	);

	// 7. Negative coordinates, inside
	Point d(-5, -5);
	Point e(5, -5);
	Point f(0, 5);

	test(
		"Inside with negative coords",
		bsp(d, e, f, Point(0, -1)),
		true
	);

	// 8. Outside negative triangle
	test(
		"Outside negative coords",
		bsp(d, e, f, Point(0, -6)),
		false
	);

	return 0;
}
