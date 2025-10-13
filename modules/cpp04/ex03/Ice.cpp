#include "Ice.hpp"
#include <iostream>

// ------------------------------------------------------------ member functions
AMateria	*Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bold at *" << target.getName() << std::endl;
}

// ---------------------------------------------------------------- constructors
Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria(other){}

// ------------------------------------------------------------------ destructor
Ice::~Ice(){}

// --------------------------------------------------- member operator overloads
Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (* this);
}
