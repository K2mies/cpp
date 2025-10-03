#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	daniel("Daniel");
	DiamondTrap	robert("Robert");

	std::cout << "\n------attack and take damage tests-------\n\n";
	for (int i = 0; i <= 5; i++)
	{
		robert.attack("Daniel");
		daniel.takeDamage(30);
	}

	std::cout << "\n-------------repair tests----------------\n\n";
	robert.beRepaired(1);

	std::cout << "\n-------------whoAmI tests----------------\n\n";
	robert.whoAmI();

	return (0);
}
