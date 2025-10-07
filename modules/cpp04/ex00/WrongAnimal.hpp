#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;
public:
// ------------------------------------------------------------ member functions
	virtual void makeSound() const;
	std::string getType() const;
// ---------------------------------------------------------------- constructors
	WrongAnimal();
	WrongAnimal(const WrongAnimal &rhs);
// ------------------------------------------------------------------ destructor
	virtual ~WrongAnimal();
// --------------------------------------------------- member operator overloads
	WrongAnimal &operator=(const WrongAnimal &rhs);
};

#endif
