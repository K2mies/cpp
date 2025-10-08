#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
// ---------------------------------------------------- private member variables
	Brain *brain;
public:
// ------------------------------------------------------------ member functions
	void	makeSound() const override;
// ---------------------------------------------------------------- constructors
	Cat();
	Cat(const Cat &other);
// ------------------------------------------------------------------ destructor
	~Cat() override;
// --------------------------------------------------- member operator overloads
	Cat &operator=(const Cat &other);
};
#endif

