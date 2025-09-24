#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed&);
	Fixed &operator=(const Fixed&);
	~Fixed();
private:
	int	_fixed_point;
	static const int frac_bits = 8;

};

//Constructor
Fixed::Fixed() : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Copy Constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

//copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixed_point = other._fixed_point;
	}
	return (*this);
}

//Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
