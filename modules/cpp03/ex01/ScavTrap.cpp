#include "ScavTrap.hpp"

//ScavTrap default constructor
ScavTrap::ScavTrap(void): ClapTrap("Default", 100, 50, 20)
{
	std::cout << "scavTrap default constructed" << std::endl;
	this->_guard = false;
}

//scavTrap constructor where name is given
ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << name << " constructed" << std::endl;
	this->_guard = false;
}

//Deconstructor
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " destructed" << std::endl;
}

//Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &rhs)
{
	std::cout << "ScavTrap " << this->_name << "copy constructor called" << std::endl;
	this->_name = rhs._name;
	this->_attack_damage = rhs._attack_damage;
	this->_energy_points = rhs._energy_points;
	this->_hit_points = rhs._hit_points;
	this->_guard = rhs._guard;
}

// asignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap " << this->_name << " copy assignment called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_attack_damage = rhs._attack_damage;
		this->_energy_points = rhs._energy_points;
		this->_hit_points = rhs._hit_points;
		this->_guard = rhs._guard;
	}
	return (*this);
}

//public member functions

//Attack
void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy_points <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " hardattack failed, not enough energy points" << std::endl;
		return ;
	}
	else if (this->_hit_points <= 0)
	{
		std::cout << "ScavTrap " << this->_name << "is dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " hardattacks " << target;
	std::cout << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points -= 1;

// Gaurd
	void	ScavTrap::guardGate(void)
	{
		if (!this->_guard && this->_hit_points > 0)
		{
			std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode" << std::endl;
			this->_guard = true;
		}
		else if (this->_hit_points <= 0)
			std::cout << "ScavTrap " << this->_name
	}
}
