#include "Weapon.hpp"


/*-----------------------------------------constructor*/
Weapon::Weapon(std::string type) : _type(type){};

/*----------------------------------------------getter*/
const std::string	&Weapon::getType()
{
	return (this->_type);
}

/*----------------------------------------------setter*/
void	Weapon::setType(std::string type)
{
		this->_type = type;
}

/*------------------------------------member functions*/
void	Weapon::attack()
{
	std::cout << "attack";
}

