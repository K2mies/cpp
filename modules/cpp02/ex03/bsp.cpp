#include "Point.hpp"

// Helper function to calculate the area of a triangle
Fixed	area(Point const a, Point const b, Point const c)
{
	Fixed	area = (a.getX() *  b.getY() - c.getY())
				  + b.getX() * (c.getY() - a.getY())
				  + c.getX() * (a.getY() - b.getY()) / 2;
	//Negate the value if sign is negative
	if (area < 0)
		area = area * (-1);
	return (area);
}

/* Function to calculate wether a point is inside a triangle or not */
/* returns True if point is inside and False if point is outside*/
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	A0 = area(a, b, c);
	Fixed	A1 = area(b, c, point);
	Fixed	A2 = area(a, c, point);
	Fixed	A3 = area(a, b, point);

	if (A1 == 0 || A2 == 0 || A3 == 0)
		return (false);

	if	   ((point.getX() == a.getX() && point.getY() == a.getY())
		||	(point.getX() == b.getX() && point.getY() == b.getY())
		||	(point.getX() == c.getX() && point.getY() == c.getY()))
		return (false);

	std::cout << "A0 is: " << A0 << std::endl << "A1 + A2 + A3 is: " << A1 + A2 + A3 << std::endl;
	return (true);
//	return (A0 == A1 + A2 + A3);

}
