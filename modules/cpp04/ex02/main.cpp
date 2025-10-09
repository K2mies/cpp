#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void	mandatory()
{
	std::cout << "====================================== Base Case ====================================\n";
	std::cout << "\n\n-------------------------------------------------------------------- Constructors\n";
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();
	std::cout << "\n\n--------------------------------------------------------------------- Destructors\n";
	delete j; //should not create a leak
	delete i;
	std::cout << "================================== Base Case Complete ===============================\n";
}

void	derived()
{
	std::cout << "\n\n-------------------------------------------------------------------- Constructors\n";
	Cat c;
	Dog d;
	AAnimal &a1 = c;
	AAnimal &a2 = d;

	std::cout << "\n\n-------------------------------------------------------------------------- sounds\n";
	a1.makeSound();
	a2.makeSound();
	std::cout << "\n\n--------------------------------------------------------------------- Destructors\n";
}

int	main()
{
	std::cout << "================================= Abstract Mandatory ================================\n";
	mandatory();
	std::cout << "============================== Abstract Mandatory Complete ==========================\n";
	std::cout << "\n=================================== Derived tests  ================================\n";
	derived();
	std::cout << "\n============================== Derived tests Complete =============================\n";
	return (0);
}
