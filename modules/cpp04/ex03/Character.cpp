#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"
#include "ansi_colors.hpp"

const std::string	id_str	= C_B_P "Character" C_RST;

// ------------------------------------------------------------ member functions
const std::string &Character::getName() const
{
	return(_name);
}

void	Character::equip(AMateria *m)
{
	for (size_t i = 0; i < N_MATERIA; i++)
	{
		if (!_invetory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	for (size_t i = 0; i < N_MATERIA; i++)
	{
		if (!floor[i])
		{
			std::cout << "Materia thrown on the floor" << std::endl;
			floor[i] = m;
			return ;
		}	
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < N_MATERIA && _inventory[idx])
	{
		for(size_t i = 0; i < 100; i++)
		{
			if (!floor[i])
			{
				floor[i] = inventory[idx];
				std::cout << "Unequped materia thrown on the floor" << std::endl;
			}
		}
	}
}
