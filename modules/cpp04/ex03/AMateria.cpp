#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "ansi_colors.hpp"

std::string const	id_str = C_B_HI_W "AMateria" C_RST;

// ------------------------------------------------------------ member functions
void	AMateria::use(ICharacter &target)
{
	std::cout << "* uses materia of type " << _type << " on " << target.getName() << std::endl;
}

AMateria::AMateria(const std::string &type): _type(type)
{
	std::cout << id_str << " String consturctor called with parameter: " << type << std::endl;
}
// ------------------------------------------------------------------ destructor
AMateria::~AMateria()
{
	std::cout << id_str << " Destructor called" << std::endl;
}
