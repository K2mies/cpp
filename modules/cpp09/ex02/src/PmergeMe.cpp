/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:14:12 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/27 13:55:55 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PmergeMe.hpp"

// --------------------------------------------------------------------- parsing
/*
* @brief main funcion to run program
*/

bool PmergeMe::run( int argc, char **argv )
{
	if ( !parse( argc, argv ) )
	{
		return ( false );
	}
	recursivelySwapVec(1);
//	std::cout << "Vector after swaps\n"
//	print_container(parsed_vec_);

	return ( true );
}

/*
* @brief main parsing function to add argv sequence to a container
*/
bool PmergeMe::parse( int argc, char **argv )
{
	if ( !parse_numbers( parsed_vec_, argc, argv ) )
	{
		std::cerr
			<< "Error: vector parsing failed"
			<< std::endl;
		return ( false ); 
	}
	std::cout << "Vector before swap: \n";
	print_container( parsed_vec_ );
	if ( !parse_numbers( parsed_deq_, argc, argv ) )
	{
		return ( false );
	}
	std::cout << "Deque before swap: \n";
	print_container( parsed_deq_ );
	return ( true ); 
}


// ------------------------------------------------------------- vector recursion
void PmergeMe::recursivelySwapVec(size_t size)
{
	std::cout << "size: " << size << std::endl;
	if ( size + 2 > parsed_vec_.size() )
		return;
	for ( size_t i = 0; i + ( size * 2 ) <= parsed_vec_.size(); i += ( size * 2 ) )
	{
		int leftEnd = parsed_vec_[i + size];
		int rightEnd = parsed_vec_[i + size + size];
		if ( leftEnd > rightEnd )
		{
			for ( size_t k = 0; k < size; k++ )
			{
				std::swap( parsed_vec_[i + k], parsed_vec_[i + size + k] );
			}
		}
		i += size;
	}
	for ( const auto &s : parsed_vec_)
	  std::cout << s << " ";
	std::cout << std::endl;
	recursivelySwapVec( size * 2 );
}
