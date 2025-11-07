#include <iostream>
#include <regex>

int main()
{
	std::string s = "Batman";
	std::regex pattern("(Bat)(.*)");
	if(std::regex_match(s, pattern))
	{
		std::cout << "Match: " << std::endl;
	}
	return (0);
}
