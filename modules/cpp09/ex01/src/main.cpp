/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:56:20 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/18 12:04:07 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	rpn( std::string const &input );

int main( int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout 
			<< "Usage: ./RPN \"<list of operands and operators>\"" 
			<< std::endl;
		return (1);
	}
	rpn( argv[1] );
	return (0);
}
