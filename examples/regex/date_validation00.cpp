#include <iostream>
#include <regex>
#include <string>
#include <chrono>

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
//	std::string line = "2023-11-15,11.47"; //valid date
	std::string line = "2023-15-15,11.47"; //invalid date
	std::regex reg(R"(((^\d{4})-(\d{2})-(\d{2})),([-+]?\d+(\.\d+)?)$)");
	std::smatch matches;

	if(std::regex_search(line, matches, reg))
	{
		std::cout << "date capture"		<< std::endl;
		std::cout << "full match:	"	<< matches[fullmatch]	<< std::endl;
		std::cout << "full date:	"	<< matches[fulldate]	<< std::endl;
		std::cout << "Year:		"		<< matches[year]		<< std::endl;
		std::cout << "Month:		"	<< matches[month]		<< std::endl;
		std::cout << "Day:		"		<< matches[day]			<< std::endl;
		std::cout << "Number:		"	<< matches[number]		<< std::endl;
		std::cout << "Decial:		"	<< matches[decimal]		<< std::endl;
	}
//---------------------------------------------------------------------------date validation
	int date_year	= std::stoi( matches[year] );
	int	date_month	= std::stoi( matches[month] );
	int date_day	= std::stoi( matches[day] );
	std::chrono::year_month_day ymd(	static_cast<std::chrono::year>( date_year ),
										static_cast<std::chrono::month>( date_month ),
										static_cast<std::chrono::day>( date_day )	);
	
	if ( !ymd.ok() )
	{
		std::cout << "date is invalid" << std::endl;
		return (1);
	}
	std::cout << "date is valid" << std::endl;
}

