#include "Zombie.hpp"

//Constructor
Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "Zombie " << name << " is created" << std::endl;
}

//Fallback Constructor (for if no argument is passed)
Zombie::Zombie()
{
    std::cout << "Zombie is created" << std::endl;
}

//Destructor
Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}

//Public member functions
void	Zombie::announce()
{
	std::cout << this->_name << ": Braiiiinnnnzzz..." << std::endl;
}

