#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define	N_SOURCEMATERIA		4

class MateriaSource : public IMateriaSource
{
	private:
	// ---------------------------------------------------- private member variables
		AMateria	*_learned[ N_SOURCEMATERIA ];
	public:	
	// ------------------------------------------------------------ member functions
		void		learnMateria(AMateria*) override;
		AMateria	*createMateria(const std::string &type) override;
	// ---------------------------------------------------------------- constructors
		MateriaSource();
		MateriaSource(const MateriaSource  &src);
	// ------------------------------------------------------------------ destructor
		~MateriaSource();
	// --------------------------------------------------- member operator overloads
		MateriaSource &operator=(MateriaSource const &src);
};

#endif
