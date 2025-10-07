#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "\n-------------Construction----------------\n\n";
	ScavTrap	daniel("Daniel");
	ScavTrap	robert("Robert");
	FragTrap	will("Will");

	std::cout << "\n------attack and take damage tests-------\n\n";
	for (int i = 0; i <= 5; i++)
	{
		robert.attack("Daniel");
		daniel.takeDamage(20);
	}
	will.attack("Robert");
	robert.takeDamage(30);

	std::cout << "\n-------------repair tests----------------\n\n";
	daniel.beRepaired(1);
	robert.beRepaired(1);

	std::cout << "\n-----------gate keep tests---------------\n\n";
	robert.guardGate();
	will.highFiveGuys();

	std::cout << "\n--------------Destruction----------------\n\n";
	return (0);
}
