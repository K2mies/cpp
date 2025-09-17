#include "Zombie.hpp"

// function declaration
void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int	main(void)
{
	std::cout << std::endl;
	std::cout << "The function randomChump creates an instance that is destroyed when out of scope" << std::endl;
	// These are only made within the scope of that function and
	// are deleted when the function ends.
	randomChump("Zombie1");
	randomChump("Zombie2");
	randomChump("Zombie3");

	std::cout << std::endl;

	std::cout << "Here we create zombies on a pointer." << std::endl;
	//these are made with new and are not deleted when the function ends.
	//function returns a pointer to a zombie with the given name.
	Zombie *zombie4 = newZombie("Zombie4");
	Zombie *zombie5 = newZombie("Zombie5");
	Zombie *zombie6 = newZombie("Zombie6");

	std::cout << std::endl;

	std::cout << "We call the function within each object to anounce itself." << std::endl;
	//announce zombies
	zombie4->announce();
	zombie5->announce();
	zombie6->announce();

	std::cout << std::endl;

	std::cout << "We use delete instead of free, and the destructor prints the info." << std::endl;

	delete zombie4;
	delete zombie5;
	delete zombie6;

	return (0);	
}
