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

	std::cout << "shortest span:	"	<< C_B_HI_Y << sp.shortestSpan()	<<	C_RST << std::endl;
	std::cout << "longest span:	"		<< C_B_HI_Y << sp.longestSpan()		<<	C_RST << std::endl;
}

void	large_random_numbers_test()
{
	Span sp = Span(BIG_NUMBER);
	std::random_device	rd;
	std::mt19937		generator( rd() );
	std::uniform_int_distribution<int>	dist( INT_MIN, INT_MAX );

	for (size_t i = 0; i < BIG_NUMBER; i++ )
		sp.addNumber(dist( generator ));

	std::cout << "shortest span:	"	<< C_B_HI_Y << sp.shortestSpan()	<< C_RST << std::endl;
	std::cout << "longest span:	"		<< C_B_HI_Y << sp.longestSpan()		<< C_RST << std::endl;
	
}

void	add_number_exceptions_test()
{
	try
	{
		Span	s( 0 );
		s.print();
		s.addNumber( 1 );
	}
	catch( std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Span	s( 3 );
		std::cout << "size set to 3..." << std::endl;
		s.addNumber( 1 );
		s.print();
		s.addNumber( 2 );
		s.print();
		s.addNumber( 3 );
		s.print();
		s.addNumber( 4 );
		s.print();
	}
	catch( std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	add_via_vector()
{
	std::vector<int>	vec = {-42, 4, INT_MIN, 1234, INT_MAX};
	try
	{
		Span	s(vec.size());
		s.print();
		for(size_t i = 0; i < vec.size(); i++)
		{
			s.addNumber(vec[i]);
		}
		s.print();
		std::cout << "shortest span:	"	<< C_B_HI_Y << s.shortestSpan()		<< C_RST << std::endl;
		std::cout << "longest span:	"		<< C_B_HI_Y << s.longestSpan()		<< C_RST << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
}


int main()
{
	std::cout << "================================== " C_B_HI_Y "Main Subject Test" C_RST " =================================\n";
	std::cout << C_B_HI_W "\n------------------------------------------------------------------------- Vector test\n" C_RST;
	subject_main();
	std::cout << "===================================== " C_B_HI_Y "Own Tests" C_RST " ======================================\n";
	std::cout << C_B_HI_W "\n----------------------------------------------------------- Add Number Exception test\n" C_RST;
	add_number_exceptions_test();
	std::cout << C_B_HI_W "\n--------------------------------------------------------------- Add via a Vector test\n" C_RST;
	add_via_vector();
	std::cout << "============================== " C_B_HI_Y "Large Random Numbers Test" C_RST " =============================\n";
	large_random_numbers_test();
	return (0);
}

