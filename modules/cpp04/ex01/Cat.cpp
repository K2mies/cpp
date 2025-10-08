#include "Cat.hpp"

// ----------------------------------------------------------------- constructor
Cat::Cat() : brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

// ------------------------------------------------------------ copy constructor
Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

// --------------------------------------------------- member operator overloads
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

// ------------------------------------------------------------------ destructor
Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

// ------------------------------------------------------------ member functions
void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
