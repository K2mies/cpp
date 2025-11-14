/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbervalidation00.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:12:57 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/14 14:31:05 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <regex>


int main( int argc, char **argv )
{

	if (argc != 2)
	{
		std::cerr << "error" << std::endl;
		return (1);
	}

	std::stringstream inputStream( argv[1] );
	if ( !inputStream )
	{
		std::cerr << "Error: could not open input string stream" << std::endl;
	}

	std::string token;
	std::regex	numFormat( R"(^[+-]?\d+$)");
	std::string const	supportedOperands = "+-/*";

	while ( inputStream >> token )
	{
		if (std::regex_match (token, numFormat))
		{
			std::cout
				<< "number: "
				<< token
				<< " is a valid number"
				<< std::endl;
		}
		else if ( token.size() == 1 && std::any_of( supportedOperands.cbegin(), supportedOperands.cend(),
													[ &x = token[0] ]( auto &y ) { return x == y;}))
		{
			std::cout
				<< token
				<< " is a valid operator"
				<< std::endl;
		}
		else
		{
			std::cout
				<< token
				<< " is not a valid number or operator (invalid)"
				<< std::endl;
		}
	}
	return (0);
}
