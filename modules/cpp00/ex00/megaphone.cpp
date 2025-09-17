#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
	   		std::string str = argv[i];
			for (char &letter : str)
				letter = std::toupper(letter);
			std::cout << str;
		}
		std::cout << std::endl;
	}
}
