#pragma once

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "ICharacter.hpp"

#define N_MATERIA 4

class Character : public ICharacter
{
	private:
	// ---------------------------------------------------- private member variables
		std::string _name;
		AMateria	*_inventory[N_MATERIA];
		AMateria	*_floor[100] = {nullptr};
	public:
	// ------------------------------------------------------------ member functions
		std::string const	&getName() const					override;
		void				equip(AMateria *m)					override;
		void				unequip(int idx)					override;
		void				use(int idx, ICharacter &target)	override;
	// ---------------------------------------------------------------- constructors
		Character() = delete;
		Character(const std::string &name);
		Character(const Character &src);
	// ------------------------------------------------------------------ destructor
		~Character();
};

#endif
