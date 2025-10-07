#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP


#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
// ------------------------------------------------------------ member functions
	void makeSound() const;
// ---------------------------------------------------------------- constructors
	WrongCat();
	WrongCat(const WrongCat &rhs);
// ------------------------------------------------------------------ destructor
	~WrongCat();
// --------------------------------------------------- member operator overloads
	WrongCat &operator=(const WrongCat &rhs);
};

#endif
