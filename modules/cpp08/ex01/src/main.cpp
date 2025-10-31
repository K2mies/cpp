/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:24:37 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/28 12:33:04 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ansi_colors.hpp"
#include "Span.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <climits>

#define BIG_NUMBER 10000

void	subject_main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan()	<< std::endl;
	std::cout << sp.longestSpan()	<< std::endl;
}

void	large_random_numbers_test()
{
	Span sp = Span(BIG_NUMBER);
	std::random_device	rd;
	std::mt19937		generator( rd() );
	std::uniform_int_distribution<int>	dist( INT_MIN, INT_MAX );

	for (size_t i = 0; i < BIG_NUMBER; i++ )
		sp.addNumber(dist( generator ));

	std::cout << sp.shortestSpan()	<< std::endl;
	std::cout << sp.longestSpan()	<< std::endl;
	
}


int main()
{
	std::cout << "================================== " C_B_HI_Y "Main Subject Test" C_RST " =================================\n";
	std::cout << C_B_HI_W "\n------------------------------------------------------------------------- Vector test\n" C_RST;
	subject_main();
	std::cout << "============================== " C_B_HI_Y "Large Random Numbers Test" C_RST " =============================\n";
	large_random_numbers_test();
	return (0);
}

