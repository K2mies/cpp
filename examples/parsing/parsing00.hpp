/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing00.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:53:08 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/20 15:22:46 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <deque>
#include <regex>

template<typename T>
bool check_for_doubles( T const &container )
{
	for ( int i = 0; i < container.size(); i++ )
	{
		for ( int j = i + 1; j < container.size(); j++ )
		{
			if ( container[j] == container[i] )
				return ( true );
		}
	}
	return ( false );
}

template<typename T>
bool parse_numbers( T &container, int argc, char **argv)
{
	//this regex expression checks for a vlid floating point
	std::regex	reg(R"(^[-+]?(\d+\.\d*)[f]?$)");

	for ( int i = 1; i < argc; ++i )
	{

		if ( std::regex_match( argv[i], reg ) )
		{
			std::cerr
				<< "Error: numbers must be positive integers only"
				<< std::endl;
			return ( false );
		}
		try
		{
			container.push_back( std::stoi( argv[i] ) );
		}
		catch( std::exception const &e )
		{
			std::cerr
				<< "Error: invalid number"
				<< std::endl;
			return ( false );
		}
		if ( std::stoi( argv[i] ) < 0)
		{
			std::cerr
				<< "Error: only positive intigers allowed"
				<< std::endl;
			return ( false );
		}
	}
	if (check_for_doubles( container ))
	{
		std::cerr
			<< "Error: no duplicates allowed"
			<< std::endl;
		return ( false ); 
	}
	return ( true );
}

template<typename T>
void print_container(T const &container)
{
	for ( size_t i = 0; i < container.size(); i++ )
	{
		std::cout
			<< container[i]
			<< std::endl;
	}
}
