#include "Fixed.hpp"

// Constuctor
Fixed::Fixed(void): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Takes const int as a paramater and stores it in bits
Fixed::Fixed(const int interger)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = (interger << Fixed::_bits);
}

// takes const float as a parameter
Fixed::Fixed(const float floating_point)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = std::roundf(floating_point * (1 << Fixed::_bits));
}

// Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

// Copy Constructor
/*Creates new object from existing bjed */
/*Called when object is created using another object as an arg */
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawBits = src.getRawBits();
}

// asignment operator overload
/* Assigns the value of one object to another*/
/* called when the '=' operator is used between two objects */
/* Fixed &Fixed returns a reference, allowing us to chain args*/
/* rhs = right hand size */
Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	// check if this is itself - then we don't copy
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return (*this);
}
//Getters and setters ============================================
//Getter
int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

//Setter
void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

//Member functions================================================

//Returns the contents of the private variable as a floating point value
float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << Fixed::_bits));
}

//Converts the fixed-point value to an integer value
int	Fixed::toInt(void) const
{
	return (this->_rawBits >> Fixed::_bits);
}

// overload of the insertion (<<) operator
std::ostream &operator<<(std::ostream &stream, Fixed const &f)
{
	stream << f.toFloat();
	return (stream);
}
