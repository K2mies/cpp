#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Arguments count error" << std::endl;
		std::cout << "Choose a LEVEL:" << std::endl;
		std::cout << "DEBUG" << std::endl;
		std::cout << "INFO" << std::endl;
		std::cout << "WARNING" << std::endl;
		std::cout << "ERROR" << std::endl;
		std::cout << "asdjkkl(other)" << std::endl;
		return (EXIT_FAILURE);
	}
	harl.complain(argv[1]);
	return (EXIT_SUCCESS);
}
