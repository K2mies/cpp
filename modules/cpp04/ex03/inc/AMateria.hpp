#pragma once

#ifndef AAMATERIA_HPP
#define AAMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
	protected:
	// -------------------------------------------------- protected member variables
		std::string _type;
	public:
	// ------------------------------------------------------------ member functions
		virtual	AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target) = 0;
	// ----------------------------------------------------------- getters & setters
		std::string const	&getType() const; 			 // Returns the materia type
	// ---------------------------------------------------------------- constructors
		AMateria() = delete;   // delete stops default constructor from being called
		AMateria(const std::string &type);
		AMateria(const AMateria &other);							 // copy constructor
	// ------------------------------------------------------------------ destructor
		virtual ~AMateria();			  // same as creating an empty deconstructor
	// --------------------------------------------------- member operator overloads
		AMateria &operator=(const AMateria &other);
};
#endif
