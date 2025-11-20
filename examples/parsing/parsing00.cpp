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
		std::cout << "Vector: \n";
		print_container( numbers );
	}
	std::cout << std::endl;
	std::deque<int>		numbers_b;
	if	( parse_numbers( numbers_b, argc, argv ) )
	{
		std::cout << "Deque: \n";
		print_container( numbers_b );
	}
	return ( 0 );
}
