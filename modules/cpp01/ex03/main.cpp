#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main()
{
	{
		Weapon type = Weapon("crude spiked baseball bat");
		HumanA bob("Bob", type);
		bob.attack();
		type.setType("enormous sword");
		bob.attack();
	}
	{
		Weapon	type = Weapon("crude spiked basball bat");
		HumanB	jim("Jim");
		jim.setWeapon(type);
		jim.attack();
		type.setType("enormous sword");
		jim.attack();
	}
}
