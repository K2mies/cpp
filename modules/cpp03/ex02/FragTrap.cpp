#include "FragTrap.hpp"

//Default Constructor
FragTrap::FragTrap(void): ClapTrap("Default", 100, 50, 30)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
}

// Constructor called with name input
FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 50, 30)
{
	std::cout << "Fragtrap " << name << " constructed" << std::endl;
}

// Deconstructor
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " destructed" << std::endl;
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap &rhs)
{
	std::cout << "FragTrap " << this->_name << " copy constructor called" << std::endl;
	this->_name = rhs._name;
	this->_attack_damage = rhs._attack_damage;
	this->_energy_points = rhs._energy_points;
	this->_hit_points = rhs._hit_points;
}

//Copy asignmenr / operator overloading
FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap " << this->_name << " copy assignment called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_attack_damage = rhs._attack_damage;
		this->_energy_points = rhs._energy_points;
		this->_hit_points = rhs._hit_points;
	}
	return (*this);
}

//Member Functions
//Attack function
void	FragTrap::attack(const std::string &target)
{
	if (this->_energy_points <= 0)
	{
		std::cout << "FragTrap " << this->_name << " superattack failed, not enough energy points" << std::endl;
		return ;
	}
	else if (this->_hit_points <= 0)
	{
		std::cout << "FragTrap " << this->_name << "is head" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << "superattacks " << target;
	std::cout << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points -= 1;
}

// High Five
void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " <<  this->_name << ": Highfive everyone!" << std::endl;
}
