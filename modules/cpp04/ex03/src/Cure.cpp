#include "Cure.hpp"
#include <iostream>
#include "ansi_colors.hpp"

// ------------------------------------------------------------ member functions
AMateria	*Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "*" C_B_HI_G " heals " C_RST << C_B_HI_R << target.getName() << "'s" << C_RST << " wounds *" << std::endl;
}

// ---------------------------------------------------------------- constructors
Cure::Cure() : AMateria("cure"){};

Cure::Cure(const Cure &other) : AMateria(other) {}

// ------------------------------------------------------------------ destructor
//in the header is ~Cure() = default which is the same as below so implamentation is not needed in this case
//Cure::~Cure(){}


// --------------------------------------------------- member operator overloads
Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}
