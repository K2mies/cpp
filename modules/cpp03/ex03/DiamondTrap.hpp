#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap:  virtual public ScavTrap, virtual public FragTrap
{
public:
// ------------------------------------------------------------ member functions
	void	whoAmI();
// ---------------------------------------------------------------- constructors
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &src);
// ------------------------------------------------------------------ destructor
	~DiamondTrap(void);
// --------------------------------------------------- member operator overloads
	DiamondTrap &operator=(DiamondTrap const &rhs);
private:
	std::string _name;
};

#endif
