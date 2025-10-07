#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap
{
	public:
// ------------------------------------------------------------ member functions
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
// ---------------------------------------------------------------- constructors
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hp, int ep, int ap);
		ClapTrap(ClapTrap const &src);
// ------------------------------------------------------------------ destructor
		~ClapTrap(void);
// --------------------------------------------------- member operator overloads
		ClapTrap & operator=(ClapTrap const & rhs);
	protected:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
};
#endif
