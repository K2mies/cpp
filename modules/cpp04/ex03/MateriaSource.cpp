#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ansi_colors.hpp"
#include <iostream>

std::string const id_str = C_B_HI_Y "MateriaSoruce" C_RST;

// ------------------------------------------------------------ member functions
void	MateriaSource::learnMateria(AMateria *m)
{
	for (size_t i = 0; i < N_SOURCEMATERIA; i++)
	{
		if (!_learned[i])
		{
			_learned[i] = m;
			return;
		}
	}
	std::cout << "materia slots are full" << std::endl;
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < N_SOURCEMATERIA; i++)
	{
		if (!_learned[i])
			return (0);
		if (_learned[i]->getType() == type)
			return (_learned[i]->clone());
		else if (_learned[i]->getType() == type)
			return (_learned[i]->clone());
	}
	return (0);
}

// ---------------------------------------------------------------- constructors
MateriaSource::MateriaSource()
{
	std::cout << id_str << " Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << id_str << " Copy constructor called" << std::endl;
	for (size_t i = 0; i < N_SOURCEMATERIA && src._learned[i]; i++)
	{
		_learned[i] = src._learned[i]->clone();
	}
}

// ------------------------------------------------------------------ destructor
MateriaSource::~MateriaSource()
{
	std::cout << id_str << " Destructor called" << std::endl;
	for (auto a : _learned)
		delete a;
}
