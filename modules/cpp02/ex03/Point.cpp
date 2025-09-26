#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	//std::cout << "Overloaded constructor called" << std::endl;
}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY())
{
	//std::cout << "Copy constructor called" << std::endl;
}

Point	&Point::operator=(const Point &other)
{
	if (this != &other) {}
	//std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Point::~Point()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}
