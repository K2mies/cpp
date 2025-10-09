#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
// ---------------------------------------------------- private member variables
	Brain *brain;
public:
// ------------------------------------------------------------ member functions
	void	makeSound() const override;
// ----------------------------------------------------------- getters & setters
	std::string getIdea(int i);
	void		setIdea(int i, std::string s);
// ---------------------------------------------------------------- constructors
	Dog();
	Dog(const Dog &other);
// ------------------------------------------------------------------ destructor
	~Dog() override;
// --------------------------------------------------- member operator overloads
	Dog &operator=(const Dog &other);
};
#endif
