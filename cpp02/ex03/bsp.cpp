#include "Point.hpp"

static void	getCoefficients(t_coef &f, Point const &a, Point const &b)
{
	f.kx = b.getY() - a.getY();
	f.ky = a.getX() - b.getX();
	f.kc = b.getX() * a.getY() - a.getX() * b.getY();
}

static void	getPartition(t_coef const &f, Point const &p, Fixed &part)
{
	part = f.kx * p.getX() + f.ky * p.getY() + f.kc;
}

// Returns true if the point is inside the triangle
static bool	bspOneSide(Point const a, Point const b, Point const c, Point const point)
{
	t_coef f;
	Fixed part1;
	Fixed part2;

	getCoefficients(f, a, b);
	getPartition(f, point, part1);
	getPartition(f, c, part2);
	if (part1 * part2 <= Fixed(0))
		return false;
	return true;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (bspOneSide(a, b, c, point) == false)
		return false;
	if (bspOneSide(b, c, a, point) == false)
		return false;
	if (bspOneSide(c, a, b, point) == false)
		return false;
	return true;
}
