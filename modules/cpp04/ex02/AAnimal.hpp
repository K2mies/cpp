#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
protected:
// -------------------------------------------------- protected member variables
	std::string type;
public:
// ------------------------------------------------------------ member functions
	virtual void	makeSound()	const = 0;
	std::string		getType()	const;
// ---------------------------------------------------------------- constructors
	AAnimal();
	AAnimal(const	AAnimal&);
// ------------------------------------------------------------------ destructor
	virtual			~AAnimal();
// --------------------------------------------------- member operator overloads
	AAnimal &operator=(const AAnimal&);
};

#endif
