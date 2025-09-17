#include "Zombie.hpp"

//Constructor
Zombie::Zombie(std::string name) : _name(name){}

//Destructor
Zombie::~Zombie(void)
{
	std::cout << this->_name << " destroyed" << std::endl;
}

//Public member functions
void	Zombie::announce()
{
	std::cout << this->_name << ":Braiiiinnnnzzz..." << std::endl;
}

