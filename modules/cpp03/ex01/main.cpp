#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "\n--------------Construction---------------\n\n";
	ScavTrap	daniel("Daniel");
	ScavTrap	robert("Robert");

	std::cout << "\n------attack and take damage tests-------\n\n";
	for (int i = 0; i <= 5; i++)
	{
		robert.attack("Daniel");
		daniel.takeDamage(20);
	}

	std::cout << "\n-------------repair tests----------------\n\n";
	daniel.beRepaired(1);
	robert.beRepaired(1);

	std::cout << "\n-----------gate keep tests---------------\n\n";
	daniel.guardGate();
	robert.guardGate();
	robert.guardGate();

	std::cout << "\n---------------Destruction---------------\n\n";
	return (0);
}
