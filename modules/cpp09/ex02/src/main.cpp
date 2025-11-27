/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:22:48 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/27 13:55:54 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PmergeMe.hpp"

int main( int argc, char **argv )
{
	if ( argc < 2 )
	{
		std::cout << "Usage: ./PmergeMe <list of positive integers\n>";
		return ( 1 );
	}
	PmergeMe pmerge;
	pmerge.run(argc, argv);
	return ( 0 ); 
}
