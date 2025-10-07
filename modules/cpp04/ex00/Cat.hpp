#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
public:
// ------------------------------------------------------------ member functions
	void	makeSound() const override;
// ---------------------------------------------------------------- constructors
	Cat();
	Cat(const Cat &rhs);
// ------------------------------------------------------------------ destructor
	~Cat() override;
// --------------------------------------------------- member operator overloads
	Cat &operator=(const Cat &rhs);
};
#endif

