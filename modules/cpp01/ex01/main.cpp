#include "Zombie.hpp"

int	main(void)
{
    std::string name;
    int         number;

    std::cout << "> enter a name: ";
    std::getline(std::cin, name);
    std::cout << "> enter a number: ";
    std::cin >> number;
    std::cout << "creating zombie horde of " << number << "..." << std::endl;

    Zombie  *horde = zombieHorde(number, name);

    if (horde)
    {
        for (int i = 0; i < number; i++)
        {
            horde[i].announce();
        }
        delete[] horde;
    }
	return (0);	
}
