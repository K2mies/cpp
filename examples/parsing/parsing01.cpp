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
		std::vector<std::vector<int>> pairs;
		add_pairs( numbers, pairs );
		print_pairs( pairs );
//		std::unordered_map<std::string, int > map;
//		add_lable(numbers, map);
//		print_unordered_map(map);
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

void	print_pairs(std::vector<std::vector<int>> &pairs)
{
	std::cout << "pairs: " << std::endl;
	for (const auto &pair : pairs)
	{
		for (int element : pair)
		{
			std::cout << element << " ,";
		}
		std::cout << std::endl;
	}
}

void	print_unordered_map(std::unordered_map<std::string, int> &map)
{
	std::cout << "unordered map contents:\n";
	for ( int i = 0; i < map.size(); i++)
	{
		int counter = (i / 2) + 1;
		std::string prefix;
		if (i % 2 == 0)
			prefix = "b";
		else
			prefix = "a";
		std::string postfix = std::to_string( counter );
		std::string key = prefix + postfix;
		std::cout << "Key: " << key << ", Value: " << map[key] << std::endl;
	}
}


