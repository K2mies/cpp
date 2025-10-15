#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ansi_colors.hpp"
#include <iostream>

int main()
{
	

	std::cout << "====================================== " C_B_HI_Y "Mandatory" C_RST " ====================================\n";
	std::cout << C_B_HI_W "\n-------------------------------------------------------------------- Constructors\n" C_RST;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure);
	
	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	std::cout << C_B_HI_W "\n----------------------------------------------------------------------------- Use\n" C_RST;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << C_B_HI_W "\n------------------------------------------------------------------ Deconstructors\n" C_RST;
	delete bob;
	delete me;
	delete src;

	return (0);

}
