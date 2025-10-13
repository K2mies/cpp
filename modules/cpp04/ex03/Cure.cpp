#include "Cure.hpp"
#include <iostream>

// ------------------------------------------------------------ member functions
AMateria	*Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

// ---------------------------------------------------------------- constructors
Cure::Cure() : AMateria("cure"){};

Cure::Cure(const Cure &other) : AMateria(other) {}

// ------------------------------------------------------------------ destructor
Cure::~Cure(){}


// --------------------------------------------------- member operator overloads
Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}
