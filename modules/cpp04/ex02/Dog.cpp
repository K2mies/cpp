#include "Dog.hpp"

// ----------------------------------------------------------------- constructor
Dog::Dog(): brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

// ------------------------------------------------------------ copy constructor
Dog::Dog(const Dog &other) : AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

// --------------------------------------------------- member operator overloads
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

// ------------------------------------------------------------------ destructor
Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

// ------------------------------------------------------------ member functions
void	Dog::makeSound() const
{
	std::cout << "wuff" << std::endl;
}

// ----------------------------------------------------------- getters & setters
std::string Dog::getIdea(int i)
{
	return (brain->getIdea(i));
}

void	Dog::setIdea(int i, std::string s)
{
	brain->setIdea(i, s);
}
