#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
class Dog: public Animal
{
public:
// ------------------------------------------------------------ member functions
	void	makeSound() const override;
// ---------------------------------------------------------------- constructors
	Dog();
	Dog(const Dog &rhs);
// ------------------------------------------------------------------ destructor
	~Dog() override;
// --------------------------------------------------- member operator overloads
	Dog &operator=(const Dog &rhs);
};

#endif
