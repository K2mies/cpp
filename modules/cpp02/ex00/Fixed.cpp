#include "Fixed.hpp"

// Constructor
Fixed::Fixed(void): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
} 

// Copy Constructor: Creates a mew pnkect from existing object
// called when  object is created using another object as arg
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawBits = src.getRawBits();
}

// Operator overloading: copy asignment operator overload
// asigns the value of one object to another
// called when the '=' operator is used between two objects
// FIxed &Fixed returns a reference
// rhs = right hand side
Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	//check if this is itself - then we do not copy
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return (*this);
}

// Getters and setters============================================

// Getter
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

// Setter
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

