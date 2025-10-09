#include "AAnimal.hpp"
#include <iostream>

// ---------------------------------------------------------------- constructors
AAnimal::AAnimal(): type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other): type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

// --------------------------------------------------- member operator overloads
AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

// ------------------------------------------------------------------ destructor
AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

// ------------------------------------------------------------ member functions
std::string AAnimal::getType() const
{
	return (type);
}

void AAnimal::makeSound() const
{
	std::cout << "Animal Sounds" << std::endl;
}
