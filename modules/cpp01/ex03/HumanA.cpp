#include "HumanA.hpp"


/*-----------------------------------------constructor*/
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){}

/*------------------------------------member functions*/
void	HumanA::attack() const
{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
