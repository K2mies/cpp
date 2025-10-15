#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"
#include "ansi_colors.hpp"

const std::string	id_str	= C_B_P "Character" C_RST;

// ---------------------------------------------------------------- constructors
Character::Character() : _name("Unnamed Character"){}

Character::Character(const std::string &name) : _name(name){}

Character::Character(const Character &other)
{
	this->_name = other._name;
	for (int i = 0 ; i < N_MATERIA; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		if (other._floor[i])
			this->_floor[i] = other._floor[i]->clone();
	}
}

// ------------------------------------------------------------------ destructor
Character::~Character()
{
	for (auto a : _inventory)
		delete a;
	for (auto a : _floor)
		delete a;
}
// --------------------------------------------------- member operator overloads
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < N_MATERIA; i++)
			delete _inventory[i];
		for (int i = 0; i < 100; i++)
			delete _floor[i];
		for (int i = 0; i < N_MATERIA; i++)
			_inventory[i] = (other._inventory[i] ? other._inventory[i]->clone() : nullptr);
		for (int i = 0; i < 100; i++)
			_floor[i] = (other._floor[i] ? other._floor[i]->clone() : nullptr);
	}
	return (*this);
}

// ------------------------------------------------------------ member functions
const std::string &Character::getName() const
{
	return(_name);
}

void	Character::equip(AMateria *m)
{
	for (size_t i = 0; i < N_MATERIA; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	for (size_t i = 0; i < N_MATERIA; i++)
	{
		if (!_floor[i])
		{
			std::cout << "Materia thrown on the floor" << std::endl;
			_floor[i] = m;
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
			if (!_floor[i])
			{
				_floor[i] = _inventory[idx];
				std::cout << "Unequped materia thrown on the floor" << std::endl;
			}
		}
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (!_inventory[idx])
		std::cout << "No materia usd" << std::endl;
	else if (idx >= 0 && idx < N_MATERIA && _inventory[idx])
			_inventory[idx]->use(target);
}
