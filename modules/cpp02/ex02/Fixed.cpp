#include "Fixed.hpp"


// CONSTRUCTION========================================================*
// Default Constructor=================================================*
Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Takes Const int as parameter========================================*
Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = (raw << Fixed::_bits);
}

// Takes Const float as parameter======================================*
Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = std::round(raw * (1 << Fixed::_bits));
}

// COPYING=============================================================*
// Taking the getBits and copying it into a new instance===============*
/* Creates new object from existing object */
/* Called when object is created using another object as an arg*/
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawBits = src.getRawBits();
}

// DESTRUCTION=========================================================*
// Destructor==========================================================*
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

// OPERATOR OVERLOADING================================================*
// assignment - operator overload where we say how does '=' work=======*
/* Assigns the value of one object to another */
/* called when the '=' operator is used between two objects*/
/* Fixed & Fixed returns a reference, allowing us to chain args */
Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return (*this);
}

// COMPARASON OPERATORS================================================*
bool	Fixed::operator	>	(const Fixed &rhs)	const
{
	return (_rawBits > rhs._rawBits);
}

bool	Fixed::operator	<	(const Fixed &rhs)	const
{
	return (_rawBits < rhs._rawBits);
}

bool	Fixed::operator	>=	(const Fixed &rhs)	const
{
	return (_rawBits >= rhs._rawBits);
}

bool	Fixed::operator <= (const Fixed &rhs)	const
{
	return (_rawBits <= rhs._rawBits);
}

bool	Fixed::operator	==	(const Fixed &rhs)	const
{
	return (_rawBits == rhs._rawBits);
}

bool	Fixed::operator	!=	(const Fixed &rhs)	const
{
	return (_rawBits != rhs._rawBits);
}

// ARITHMETIC OPERATORS================================================*
Fixed	Fixed::operator	+	(const Fixed &rhs)	const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator	-	(const Fixed &rhs)	const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator	*	(const Fixed &rhs)	const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator	/	(const Fixed &rhs)	const
{
	if (rhs._rawBits == 0)
	{
		std::cerr << "- cannot devide by zero" << std::endl;
		exit(1);
	}
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

// INCREMENT AND DECREMENT OPERATORS===================================*
Fixed	&Fixed::operator	++	(void)
{
	//prefex
	this->_rawBits++;
	return(*this);
}

Fixed	&Fixed::operator	--	(void)
{
	//prefex
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator	++	(int)
{
	//postfix
	Fixed	tmp(*this);
	_rawBits++;
	return (tmp);
}

Fixed	Fixed::operator	--	(int)
{
	//postfix
	Fixed tmp(*this);
	this->_rawBits--;
	return (tmp);	
}

// MEMBER FUNCTIONS====================================================*
// STATIC MIN/MAX======================================================*
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}

// GETTERS/SETTERS=====================================================*
// GET=================================================================*
int	Fixed::getRawBits(void)	const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}
// SET=================================================================*
void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

// CONVERSION=========================================================*
/*converts the fixed-point value to a floating-point value.*/
float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << Fixed::_bits));
}
/*converts the fixed-point value to an integer value.*/
int	Fixed::toInt(void) const
{
	return (this->_rawBits >> Fixed::_bits);
}

// OUTPUT OPERATOR OVERLOAD============================================*
/*output - operator overload where we say how does '<<' work*/
std::ostream	&operator	<<	(std::ostream &stream, Fixed const &f)
{
	stream << f.toFloat();
	return (stream);
}
