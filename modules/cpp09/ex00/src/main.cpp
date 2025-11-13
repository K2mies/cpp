/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:35:26 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/11 12:36:08 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cout << "Usage: ./btc <input_file_name>" << std::endl;
		return ( 1 );
	}
	BitcoinExchange b( argv[1] );
	b.run();
	return (0);
}
