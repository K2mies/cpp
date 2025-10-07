#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

void	mandatory()
{
	std::cout << "\n\n---------------------------------------------------------------------Constructors\n";
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << "\n\n----------------------------------------------------------------------------types\n";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "\n\n---------------------------------------------------------------------------sounds\n";
	i->makeSound(); // Will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "\n\n----------------------------------------------------------------------Destructors\n";
	delete meta;
	delete i;
	delete j;
}

void wrongtest()
{

	std::cout << "\n\n---------------------------------------------------------------------Constructors\n";
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *i = new WrongCat();
	std::cout << "\n\n----------------------------------------------------------------------------types\n";
	std::cout << i->getType() << " " << std::endl;
	std::cout << "\n\n---------------------------------------------------------------------------sounds\n";
	i->makeSound(); //Will output the wrong cat sound!
	meta->makeSound();
	std::cout << "\n\n----------------------------------------------------------------------Destructors\n";
	delete meta;
	delete i;
}

void	owntest()
{
	std::cout << "\n\n-----------------------------------Animal test-----------------------------------\n";
		{
			Animal a;
			Animal b(a);
			Animal c;
			c = a;
			std::cout << a.getType() << std::endl;
			a.makeSound();
		}
	std::cout << "----------------------------------Animal test complete-------------------------------\n\n";
	std::cout << "\n\n-------------------------------------Dog test------------------------------------\n";
	{
		std::cout << "\n\n---------------------------------------------------------------------Constructors\n";
		Dog a;
		Dog b(a);
		Dog c;
		c = a;
		std::cout << "\n\n----------------------------------------------------------------------------types\n";
		std::cout << a.getType() << " " << b.getType() << " " << c.getType() << std::endl;
		std::cout << "\n\n---------------------------------------------------------------------------sounds\n";
		a.makeSound();
		b.makeSound();
		c.makeSound();
		std::cout << "\n\n----------------------------------------------------------------------Destructors\n";
	}
	std::cout << "- Dog test complete -" << std::endl;
	std::cout << "--------------------------------Dog test complete--------------------------------\n\n";
	std::cout << "\n\n-------------------------------------Cat test------------------------------------\n";
	{
		std::cout << "\n\n---------------------------------------------------------------------Constructors\n";
		Cat a;
		Cat b(a);
		Cat c;
		c = a;
		std::cout << "\n\n----------------------------------------------------------------------------types\n";
		std::cout << a.getType() << " " << b.getType() << " " << c.getType() << std::endl;
		std::cout << "\n\n---------------------------------------------------------------------------sounds\n";
		a.makeSound();
		b.makeSound();
		c.makeSound();
		std::cout << "\n\n----------------------------------------------------------------------Destructors\n";
	}
	std::cout << "------------------------------------Cat test complete--------------------------------\n\n";
}

int	main()
{
	std::cout << "====================================== Mandatory ====================================\n";
	mandatory();
	std::cout << "================================== Mandatory complete ===============================\n\n";
	std::cout << "===================================== Wrong Test ====================================\n";
	wrongtest();
	std::cout << "================================= Wrong test complete ===============================\n\n";
	std::cout << "====================================== Own Test =====================================\n";
	owntest();
	std::cout << "================================== Own test complete ================================\n\n";
	return (0);
}
