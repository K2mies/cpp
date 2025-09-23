#include "Integer.class.hpp"

//Constructor
Integer::Integer(int const n) : _n(n)
{
	std::cout << "Constructor called with value: " << n << std::endl;
	return ;
}

//Destructor
Integer::~Integer(void)
{
	std::cout << "Destructor called with value " << this->_n << std::endl;
	return ;
}

int	Integer::getValue(void) const
{
	return (this->_n);
}

