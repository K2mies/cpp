#include "Zombie.hpp"

// makes a zombie with a name and announces it
// zombie is deconstructed when the function ends
void	randomChump (std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
