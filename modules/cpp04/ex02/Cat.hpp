#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
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
	Cat();
	Cat(const Cat &other);
// ------------------------------------------------------------------ destructor
	~Cat() override;
// --------------------------------------------------- member operator overloads
	Cat &operator=(const Cat &other);
};
#endif

