#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "\n--------------Construction---------------\n\n";
	ClapTrap	empty;
	ClapTrap	daniel("Daniel");
	ClapTrap	robert("Robert");

	std::cout << "\n-----attack and take damage tests------\n\n";
	daniel.attack("Robert");
	robert.takeDamage(0);

	std::cout << "\n-------------repair tests--------------\n\n";
	for (int i = 0; i <= 10; i++)
	{
		robert.beRepaired(1);
	}
	std::cout << "\n-------take damange tests--------------\n\n";
	robert.takeDamage(21);
	daniel.attack("Robert");
	robert.takeDamage(0);
	std::cout << "\n---------------Destruction---------------\n\n";
	return (0);
}
