#include <iostream>
#include <regex>
#include <string>

enum regexMatch : unsigned int
{
		fullmatch,
		fulldate,
		year,
		month,
		day,
		number,
		decimal
};

int	main()
{
	std::string line = "2023-11-15,11.47";
//	std::regex pattern("Date: (\\d{4})-(\\d{2})-(\\d{2})");
//	std::regex pattern(R"((\d{4})-(\d{2})-(\d{2}))");
	std::regex reg(R"(((^\d{4})-(\d{2})-(\d{2})),([-+]?\d+(\.\d+)?)$)");
//	std::regex pattern(R"(Date: (\d{4})-(0[1-9]1[0-2])-(\d{2}))");
	std::smatch matches;

	if(std::regex_search(line, matches, reg))
	{
		std::cout << "full match:	"	<< matches[fullmatch]	<< std::endl;
		std::cout << "full date:	"	<< matches[fulldate]	<< std::endl;
		std::cout << "Year:		"		<< matches[year]		<< std::endl;
		std::cout << "Month:		"	<< matches[month]		<< std::endl;
		std::cout << "Day:		"		<< matches[day]			<< std::endl;
		std::cout << "Number:		"	<< matches[number]		<< std::endl;
		std::cout << "Decial:		"	<< matches[decimal]		<< std::endl;
	}
}
