/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing00.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:10:17 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/20 16:03:41 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <deque>
#include "parsing00.hpp"

int main(int argc, char **argv)
{
	if ( argc < 2 )
	{
		std::cout << "Usage: ./pergeMe <list of positive integers>" << std::endl;
		return ( 1 );
	}

	std::vector<int>	numbers;
	if ( parse_numbers( numbers, argc, argv ) )
	{
		std::cout << "Vector before swap: \n";
		print_container( numbers );
		swap_values( numbers );
		std::cout << "Vector after swap: \n";
		print_container( numbers );
		std::unordered_map<std::string, int > map;
		add_lable(numbers, map);
		print_unordered_map(map);
	}
	std::cout << std::endl;


	std::deque<int>		numbers_b;
	if	( parse_numbers( numbers_b, argc, argv ) )
	{
		std::cout << "Deque before swap: \n";
		print_container( numbers_b );
		swap_values( numbers_b );
		std::cout << "Deque after swap: \n";
		print_container( numbers_b );
	}

	return ( 0 );
}

void	print_unordered_map(std::unordered_map<std::string, int> &map)
{
	std::cout << "unordered map contents:\n";
	int counter = 1;
	for ( int i = 0; i < map.size(); i++)
	{
		std::string prefix;
		if (i % 2 == 0)
			prefix = "a";
		else
			prefix = "b";
		std::string postfix = std::to_string( counter );
		std::string key = prefix + postfix;
		std::cout << "Key: " << key << ", Value: " << map[key] << std::endl;
		counter++;	
	}
//	for ( const auto &pair : map)
//	{
//		const std::string &key = pair.first;
//
//		int value = pair.second;
//
//	  std::cout << "key: " << key << ", Value: " << value << std::endl;
//	}
}
