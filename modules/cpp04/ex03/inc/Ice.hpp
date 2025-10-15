#pragma once

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	protected:
	// -------------------------------------------------- protected member variables
		const std::string _type;
	public:
	// ------------------------------------------------------------ member functions
	AMateria	*clone() const override;
	void		use(ICharacter &target) override;
	// ---------------------------------------------------------------- constructors
	Ice();
	Ice(const Ice &copy);
	// ------------------------------------------------------------------ destructor
	~Ice();			   // default = same as creating an empty destructor
	// --------------------------------------------------- member operator overloads
	Ice &operator=(const Ice &copy);
};
#endif
