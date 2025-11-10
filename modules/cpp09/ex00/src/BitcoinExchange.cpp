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
/* -------------------------------------------------------------------------- */
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
/* -------------------------------------------------------------------------- */
BitcoinExchange::BitcoinExchange( std::string const &inputFileName,
								  std::string const &dataFileName )
	:	_dataFileName( dataFileName),
		_inputFileName( inputFileName) {}
/* -------------------------------------------------------------------------- */

void	BitcoinExchange::run()
{
	dataParse();
	inputParse();
}

bool BitcoinExchange::dataParse()
{
	std::ifstream dataFile( _dataFileName );

	if ( !dataFile )
	{
		std::cout	<< C_B_HI_R << "Error: " << C_RST << " could not open data base file"
					<< C_B_HI_R << _dataFileName << C_RST << std::endl;
		return ( false );
	}
	auto streamStart = dataFile.tellg(); //bookmarks the start position of the file
	std::string line;

	std::getline(dataFile, line);
	if ( line.empty() && !dataFile) //check for empty file (a single newline also counts)
	{
		std::cout << C_B_HI_R << "Error: " << C_RST << " Empty data file" << std::endl;
	}
	dataFile.seekg( streamStart ); //Restore stream to start of file.
	/* -------------------------------------------------------------------------- */
	
	std::regex reg(R"(((^\d{4})-(\d{2})-(\d{2})),([-+]?\d+(\.\d+)?)$)");
	return ( true );
}
