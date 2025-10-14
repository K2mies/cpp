#include <iostream>
#include "File.hpp"

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

    File    in_file(filename, std::ios::in);
    in_file.readFromFile();
    in_file.replace(s1, s2);
    in_file.writeToFile(filename + ".replace");
}
