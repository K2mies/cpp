#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void	mandatorybrain()
{
	std::cout << "\n\n---------------------------------------------------------------------Constructors\n";
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << "\n\n----------------------------------------------------------------------Destructors\n";
	delete j; //should not create a leak
	delete i;

	std::cout << "\n\n---------------------------------- Animals test ---------------------------------\n";
	Animal *animals[100];
	std::cout << "\n\n---------------------------------------------------------------------Constructors\n";
	for (int i = 0; i < 50; i++)
	{
		animals[i] = new Cat();
	}
	for (int i = 50; i < 100; i++)
	{
		animals[i] = new Dog();
	}
	std::cout << "\n\n----------------------------------------------------------------------------types\n";
	for (int i = 0; i < 100; i++)
	{
		std::cout << animals[i]->getType() << std::endl;
	}
	std::cout << "\n\n----------------------------------------------------------------------Destructors\n";
	for (int i = 0; i < 100; i++)
	{
		delete animals[i];
	}
	std::cout << "--------------------------------- Animals test complete -----------------------------\n\n";
}


int	main()
{
	std::cout << "=================================== Brain Mandatory =================================\n";
	mandatorybrain();
	std::cout << "=============================== Brain Mandatory Complete ============================\n";
	return (0);
}
