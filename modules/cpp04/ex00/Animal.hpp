#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;
public:
// ------------------------------------------------------------ member functions
	virtual void makeSound() const;
	std::string getType() const;
// ---------------------------------------------------------------- constructors
	Animal();
	Animal(const Animal&);
// ------------------------------------------------------------------ destructor
	virtual ~Animal();
// --------------------------------------------------- member operator overloads
	Animal &operator=(const Animal&);
};

#endif
