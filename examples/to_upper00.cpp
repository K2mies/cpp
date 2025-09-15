#include <iostream>
#include <string>

int	main()
{
	std::string str = "test";
	for (char &letter : str)
		letter = std::toupper(letter);
	std::cout << str << std::endl;
		
	return (0);
}
