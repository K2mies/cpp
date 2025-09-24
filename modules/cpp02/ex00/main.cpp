#include "Fixed.hpp"

#include <iostream>

int	main()
{
	Fixed	a;		//default constructor called
	Fixed	b(a);	//copy constructor called
	Fixed	c;		//default constructor called
	
	c = b;			//assignment operator called
	
	std::cout << a.getRawBits() << std::endl;	//print raw bits of a
	std::cout << b.getRawBits() << std::endl;	//print raw bits of b
	std::cout << c.getRawBits() << std::endl;	//print raw bits of c
	return (0);
}
