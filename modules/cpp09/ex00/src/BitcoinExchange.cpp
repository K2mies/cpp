/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:35:30 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/10 15:41:29 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "BitcoinExchange.hpp"
#include "ansi_colors.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <chrono>
#include <iomanip>
#include <string>

// ----------------------------------------------------------------- definitions

static bool lineMatchesFormat(		std::string	const	&line,
									std::smatch			&matches,
									std::regex	const	&reg,
									size_t				lineCounter,
									std::string const	&fileType	);

static bool	isValidDate(			std::smatch const	&matches, 
									std::string const	&fileType,
									size_t				lineCounter	);

static bool floatValueOverflows(	std::smatch const	&matches,
									std::string const	&fileType,
									size_t				lineCounter);
// ----------------------------------------------------------------------- enums
enum regexMatch	: unsigned int
{
	fullmatch,
	fulldate,
	year,
	month,
	day,
	number,
	decimal
};
// ---------------------------------------------------------------- constructors
BitcoinExchange::BitcoinExchange(	std::string const	&inputFileName,
									std::string const	&dataFileName )
	:	_dataFileName(	dataFileName ),
		_inputFileName(	inputFileName ) {}
// ------------------------------------------------------------ member functions

void	BitcoinExchange::run()
{
	dataParse();
	inputParse();
}

bool BitcoinExchange::dataParse()
{
	// --------------------------------------------------------------- file handling
	std::ifstream dataFile( _dataFileName );

	if ( !dataFile )
	{
		std::cout
			<< C_B_HI_R
			<< "Error: "
			<< C_RST
			<< " could not open data base file"
			<< C_B_HI_R
			<< _dataFileName
			<< C_RST
			<< std::endl;
		return ( false );
	}
	auto streamStart = dataFile.tellg(); //bookmarks the start position of the file
	std::string line;

	std::getline( dataFile, line );
	if ( line.empty() && !dataFile ) //check for empty file (a single newline also counts)
	{
		std::cout
			<< C_B_HI_R
			<< "Error: "
			<< C_RST
			<< " Empty data file"
			<< std::endl;
	}
	dataFile.seekg( streamStart ); //Restore stream to start of file.
	// ----------------------------------------------------------------------- regex
	std::regex	reg(R"(((^\d{4})-(\d{2})-(\d{2})),([-+]?\d+(\.\d+)?)$)");
	std::smatch matches;
	size_t		lineCounter = 0;
	// ------------------------------------------------------------------------ loop
	while ( std::getline( dataFile, line ) )
	{
		++lineCounter;

		//check if first line is header
		if ( lineCounter == 1 && !std::regex_match( line, matches, reg ) )
			continue;

		if ( !lineMatchesFormat( line, matches, reg, lineCounter, "Data file" ) )
			continue;

		if ( !isValidDate( matches, "Data File", lineCounter ) )
			continue;

		//if it clears all checks then it creats an element/key in the map and asigns the value
		if ( !floatValueOverflows( matches, "Data File", lineCounter ) )
			_data[ matches[fulldate] ] = std::stof( matches[number] );
	}
	return ( true );
	/* -------------------------------------------------------------------------- */
}

bool BitcoinExchange::inputParse()
{
	// --------------------------------------------------------------- file handling
	std::ifstream inputFile( _inputFileName );
	if ( !inputFile )
	{
		std::cout
			<< C_B_HI_R
			<< "Error: "
			<< "Couldn't open input file "
			<< _inputFileName
			<< C_RST
			<< std::endl;
		return ( false );
	}

	auto	streamStart = inputFile.tellg();
	std::string line;

	std::getline( inputFile, line );
	if ( line.empty() && !inputFile )
	{
		std::cout
			<< C_B_HI_R
			<< "Error: "
			<< "Empty Input file."
			<< C_RST
			<< std::endl;
	}

	inputFile.seekg( streamStart ); //resets filestream to begining of file.
	// ----------------------------------------------------------------------- regex
	std::regex	reg( R"(\s*((\d{4})-(\d{2})-(\d{2}))\s*\|\s*([+-]?\d+(\.\d+)?)\s*$)" );
	std::smatch	matches;
	size_t		lineCounter = 0;
	// ------------------------------------------------------------------------ loop
	while ( std::getline( inputFile, line ) )
	{
		++lineCounter;

		if ( lineCounter == 1 && !std::regex_match( line, matches, reg ) )
			continue;

		if ( !lineMatchesFormat( line, matches, reg, lineCounter, "Input file") )
			continue;

		if ( !isValidDate( matches, "Input file", lineCounter ) )
			continue;

		if ( floatValueOverflows( matches, "Input file", lineCounter ) )
			continue;

		float	value = std::stof( matches[number] );
	// ---------------------------------------------------------------- float limits
		if ( value < 0 )
		{
			std::cout
				<< C_B_HI_R
				<< "Error: "
				<< "Input file: line "
				<< lineCounter
				<< ": number "
				<< matches[number]
				<< " is not positive"
				<< C_RST
				<< std::endl;
			continue;
		}

		if ( value > 1000 )
		{
			std::cout
				<< C_B_HI_R
				<< "Error: "
				<< "Input file: line "
				<< lineCounter
				<< ": number "
				<< matches[number]
				<< " is over 1000"
				<< C_RST
				<< std::endl;
			continue;
		}
	// ---------------------------------------------------------------- closest date
		std::string closestDate = std::string( 10, 0 );

		for ( auto &d : _data)
		{
			if ( d.first <= matches[fulldate] && d.first > closestDate )
				closestDate = d.first;
			if ( closestDate == matches[fulldate] )
				break;
		}
	// ------------------------------------------------------------------ conversion
		std::setprecision( 15 );

		if ( closestDate[0] != 0 )
		{
			float	bitcoinValue = _data[closestDate];
			std::cout
				<< matches[fulldate]
				<< " | "
				<< std::left
				<< std::setw( 6 )
				<< value
				<< " => "
				<< closestDate
				<< ", "
				<< std::setw( 6 )
				<< bitcoinValue
				<< " => "
				<< std::right
				<< std::setw( 6 )
				<< value
				<< " * "
				<< std::left
				<< std::setw( 6 )
				<< bitcoinValue
				<< " = "
				<< value * bitcoinValue
				<< std::endl;
		}
		else
		{
			std::cout
				<< C_B_HI_R
				<< "Error:"
				<< " Input file: line "
				<< lineCounter
				<< ": no matching or earlier date in database."
				<< C_RST
				<< std::endl;
		}
	}
	return ( true );
}
// ------------------------------------------------------------ static functions

static bool lineMatchesFormat(	std::string	const	&line,
							    std::smatch			&matches,
								std::regex	const	&reg,
								size_t				lineCounter,
							    std::string const	&fileType	)
{
	if (!std::regex_match( line, matches, reg) )
	{
		std::cout
			<< C_B_HI_R
			<< "Error: "
			<< fileType
			<< ": line "
			<< lineCounter
			<< ": bad input: "
			<< line
			<< C_RST
			<< std::endl;
		return ( false );
	}
	return ( true );
}

static bool	isValidDate(	std::smatch const	&matches,
							std::string const	&fileType,
							size_t				lineCounter	)
{
	int date_year	= std::stoi( matches[year] );
	int	date_month	= std::stoi( matches[month] );
	int date_day	= std::stoi( matches[day] );
	std::chrono::year_month_day ymd(	static_cast<std::chrono::year>( date_year ),
										static_cast<std::chrono::month>( date_month ),
										static_cast<std::chrono::day>( date_day )	);
	if (!ymd.ok())
	{
		std::cout
			<< C_B_HI_R 
			<< "Error:"
			<< " "
			<< fileType
			<< ": line "
			<< lineCounter
			<< ": date "
			<< matches[fulldate]
			<< " is invalid"
			<< std::endl
			<< C_RST;
		return ( false );
	}
	return ( true );
}

static bool floatValueOverflows(	std::smatch const	&matches,
									std::string const	&fileType,
									size_t				lineCounter	)
{
	try
	{
		std::stof( matches[number] );
	}
	catch( std::exception const &e)
	{
		std::cout
			<< C_B_HI_R
			<< "Error:"
			<< " "
			<< fileType
			<< ": line "
			<< lineCounter
			<< ": value "
			<< matches[number]
			<< C_RST 
			<< " is invalid"
			<< std::endl;
		return ( true );
	}
	return ( false );
}
