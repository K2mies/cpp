#include "Ice.hpp"
#include <iostream>
#include "ansi_colors.hpp"
// ------------------------------------------------------------ member functions
AMateria	*Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an" C_B_HI_B " ice bolt " C_RST "at" << C_B_HI_R << " " << target.getName() << C_RST  << " *"<< std::endl;
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
