#include <iostream>

int	main()
{
	std::string	filename;
	std::string	s1;
	std::string	s2;

	std::cout << "> enter file name to edit ";
	std::cin >> filename;
	std::cout << "> enter string to search: ";
	std::cin >> s1;
	std::cout << "> enter replacement string: ";
	std::cin >> s2;

	std::cout << filename << " " << s1 << " " << s2 << " " << std::endl;
}
