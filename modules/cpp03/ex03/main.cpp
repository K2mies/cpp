#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "\n-------------Construction----------------\n\n";
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
	daniel.whoAmI();
	std::cout << "\n--------------Destruction----------------\n\n";
	return (0);
}
