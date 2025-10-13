#pragma once

#ifndef AAMATERIA_HPP
#define AAMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
	protected:
	// -------------------------------------------------- protected member variables
		const std::string _type;
	public:
	// ------------------------------------------------------------ member functions
		virtual	AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
	// ----------------------------------------------------------- getters & setters
		std::string const	&getType() const; 			 // Returns the materia type
	// ---------------------------------------------------------------- constructors
		AMateria() = delete;
		AMateria(const std::string &type);
		AMateria(const AMateria &copy);				 // copy constructor
	// ------------------------------------------------------------------ destructor
		virtual ~AMateria();	  // same as creating an empty deconstructor
	// --------------------------------------------------- member operator overloads
		AMateria &operator=(const AMateria &copy);
};
#endif
