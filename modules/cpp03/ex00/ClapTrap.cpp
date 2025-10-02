#include "ClapTrap.hpp"

// Constructor that takes no input
ClapTrap::ClapTrap(void): _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

// Constructor for if name is given
ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(ClapTrap const &src)
{
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	std::cout << "ClapTrap " << this->_name << " copy constructor called" << std::endl;
}

// '=' Operator overload / Asignment operator
ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	std::cout << "ClapTrap " << this->_name << " copy asignment called" << std::endl;
	return (*this);
}
// Public Member Functions

// Function to attack a target
void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " attack failed, not enough energy points" << std::endl;
		return ;
	}
	else if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap"  << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points -= 1;
}

//Function to take damage
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is_dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " took damage " << amount << " points!" << std::endl;
	this->_hit_points -= amount;
}

//Function to repair self
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " repair failed, not enough energy points!" << std::endl;
		return ;
	}
	else if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " repairs himself " << amount << " points!" << std::endl;
	this->_hit_points += amount;
	this->_energy_points -= 1;
}
