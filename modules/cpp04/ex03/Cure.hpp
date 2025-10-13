#pragma once

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	protected:
	// -------------------------------------------------- protected member variables
		const std::string _type;
	public:
	// ------------------------------------------------------------ member functions
	AMateria	*clone() const override;
	void		use(ICharacter &target) override;
	// ---------------------------------------------------------------- constructors
	Cure();
	Cure(const Cure &copy);
	// ------------------------------------------------------------------ destructor
	~Cure();			   // default = same as creating an empty destructor
	// --------------------------------------------------- member operator overloads
	Cure &operator=(const Cure &copy);
};
#endif
