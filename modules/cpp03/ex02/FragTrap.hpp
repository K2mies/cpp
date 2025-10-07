#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"


class FragTrap: public ClapTrap
{
public:
// ------------------------------------------------------------ member functions
	void	attack(const std::string &target);
	void	highFiveGuys(void);
// ---------------------------------------------------------------- constructors
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &rhs);
// ------------------------------------------------------------------ destructor
	~FragTrap(void);
// --------------------------------------------------- member operator overloads
	FragTrap &operator=(const FragTrap &rhs);
};

#endif
