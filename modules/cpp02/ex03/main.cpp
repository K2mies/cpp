#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	isInside(Point const a, Point const b, Point const c, Point const point)
{
	std::cout << "point a = " << a.getX() << ','  << a.getY() << std::endl;
	std::cout << "point b = " << b.getX() << ','  << b.getY() << std::endl;
	std::cout << "point c = " << c.getX() << ','  << c.getY() << std::endl;
	std::cout << "point = " << point.getX() << ','  << point.getY() << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
	std::cout << std::endl;

}

int	main(void)
{
	Point	a(-8, 0);
	Point	b(8, 0);
	Point	c(-1, 3);
	Point	point(-1, 3);

	//should be outside triangle
	isInside(a, b, c, point);

	Point	a_2(0, 0);
	Point	b_2(10, 30);
	Point	c_2(20, 0);
	Point	second_point(10, 15);

	//should be inside triangle
	isInside(a_2, b_2, c_2, second_point);

	return (0);
}
