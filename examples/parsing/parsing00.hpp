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
#include <unordered_map>
#include <string>

void	print_unordered_map(std::unordered_map<std::string, int> &map);
//void	print_unordered_map(std::unordered_map<std::string, int> &map);
//
//template<typename T>
//void swap_values(T &container)
//{
//	for ( int i = 0; i < container.size() - 1; i += 2 )
//	{
//		if ( container[i] > container[i + 1] )
//		{
//			std::swap( container[i], container[i + 1]);
//		}
//	}
//}

template<typename T>
void	add_lable(T &container, std::unordered_map<std::string, int> &map)
{
	//std::unordered_map<std::string, int> map;
	//int	counter = 1;
	std::string prefix;
	std::string postfix;
	std::string key;

	for ( int i = 0; i < container.size(); i++ )
	{
		int counter = (i / 2) + 1;
	
		if (i % 2 == 0)
		{
			prefix = "b";
			//postfix = std::to_string( i );
		}
		else
		{
			prefix = "a";
			//postfix = std::to_string( i - 1 );
		}
		postfix = std::to_string( counter );
		key = prefix + postfix;
		map[key] = container[i];
		//counter++;
	}
}

template<typename T>
void add_pairs(T const &container)
{
	std::vector<std::vector> pairs;
	for ( int i = 0; i < container.size(); i++ )
	{
		std::vector pair;
		if ( i % 2 != 0 )
		{
			pair.push_back( container[i] );
		}
		else
		{
			pair.push_back( container[i] );
		}
		pairs.push_back( pair );
	}
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
	std::regex	reg_a(R"(^[-+]?(\d+\.\d*)[f]?$)"); // checks for valid floating point
	std::regex	reg_b(R"(\d+([^\d\s])\d+)"); // checks for invalid symbol between two numbers

	for ( int i = 1; i < argc; i++ )
	{
		if ( std::regex_match( argv[i], reg_a ) )
		{
			std::cerr
				<< "Error: numbers must be positive integers only (floating point numbers not allowed)"
				<< std::endl;
			return ( false );
		}
		if ( std::regex_match( argv[i], reg_b ) )
		{
			std::cerr
				<< "Error: invalid symbols"
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
void	swap_values(T &container)
{
	for ( size_t i = 0; i < container.size() - 1; i += 2 )
	{
		if ( container[i] > container[i + 1])
		{
			std::swap( container[i], container[i + 1] );
		}
	}
}

