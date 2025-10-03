#include "DiamondTrap.hpp"

//Constructor
DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = "Default";
	ClapTrap::_name = "Default_clap_name";
	this->_hit_points = ScavTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;

	std::cout << "DiamondTrap Default constructed" << std::endl;
}

//Constructor with name input
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	ClapTrap::_name + "_clap_name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;

	std::cout << "DiamondTrap " << this->_name << " constructed" << std::endl;
}

//Copy constructpr
DiamondTrap::DiamondTrap(DiamondTrap const &src): ScavTrap(src), FragTrap(src)
{
	this->ClapTrap::_name = src.ClapTrap::_name;
	std::cout << "DiamondTrap " << this->_name << " copy constructor called" << std::endl;
}

//Destructor
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " destructed" << std::endl;
}

//Asignment operator
DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	std::cout << "DiamondTrap " << this->_name << " copy assignment called" << std::endl;
	return (*this);
}
