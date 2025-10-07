#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
public:
// ------------------------------------------------------------ member functions
	void	attack(const std::string &target);
	void	guardGate(void);
// ---------------------------------------------------------------- constructors
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &rhs);
// ------------------------------------------------------------------ destructor
	~ScavTrap(void);
// --------------------------------------------------- member operator overloads
	ScavTrap &operator=(const ScavTrap &rhs);
protected:
	bool	_guard;
};

#endif
