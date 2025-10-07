#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs): type(rhs.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "WrongAnimal copy asignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called " << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Sounds" << std::endl;
}
