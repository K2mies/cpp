#include "Point.hpp"

// Helper function to calculate the area of a triangle
Fixed	area(Point const a, Point const b, Point const c)
{
	Fixed	area = (a.getX() * (b.getY() - c.getY())
				  + b.getX() * (c.getY() - a.getY())
				  + c.getX() * (a.getY() - b.getY())) / 2;
	//Negate the value if sign is negative
	if (area < 0)
		area = area * (-1);
	return (area);
}

/* Function to calculate wether a point is inside a triangle or not */
/* returns True if point is inside and False if point is outside*/
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	//A0 is the area of the main triangle.
	Fixed	A0 = area(a, b, c);
	// A1, A2, A3 are the areas of the three sub-triangles formed with 'point'
	Fixed	A1 = area(b, c, point);
	Fixed	A2 = area(a, c, point);
	Fixed	A3 = area(a, b, point);

	//Check for if points are exactly on the boundary (area of sub-triangle is 0)
	if (A1 == 0 || A2 == 0 || A3 == 0)
		return (false);

	//Check if point is exactly on vertex
	if	   ((point.getX() == a.getX() && point.getY() == a.getY())
		||	(point.getX() == b.getX() && point.getY() == b.getY())
		||	(point.getX() == c.getX() && point.getY()== c.getY()))
		return (false);

	//Check Final check if point is inside traingle or not
	return (A0 == A1 + A2 + A3);

}
