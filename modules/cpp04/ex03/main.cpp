#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ansi_colors.hpp"
#include <iostream>

int main()
{
	
	std::cout << "================================= Abstract Mandatory ================================\n";
	std::cout << "\n\n--------------------------------------------------------------------- Destructors\n";


	std::cout << "====================================== Test one =====================================\n";
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure);

}
