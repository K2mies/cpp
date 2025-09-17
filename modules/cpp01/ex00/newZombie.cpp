#include "Zombie.hpp"

// returns a pointer to a zombie with the given name.

Zombie	*newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);
	return zombie;
}
