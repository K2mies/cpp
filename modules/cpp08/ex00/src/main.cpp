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
#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <array>

int main()
{
	std::cout << "======================================= " C_B_HI_Y "Tests" C_RST " ========================================\n";
	std::cout << C_B_HI_W "\n------------------------------------------------------------------------- Vector test\n" C_RST;
	std::vector<int>	vec = {-1, 0, 1, 2, 3, 42, 50};
	try
	{
		int num = 42;
		std::cout << "Looking for number:	"	<< C_B_HI_Y << num		<< C_RST << std::endl;
		int found = *easyfind< std::vector<int> >(vec, num);
		std::cout << "Found number:		"		<< C_B_HI_Y << found	<< C_RST << std::endl;
		std::cout << std::endl;

		num = 420;
		std::cout << "Looking for number:	"	<< C_B_HI_Y << num		<< C_RST << std::endl;
		found = *easyfind< std::vector<int> >(vec, num);
		std::cout << "Found number:		"		<< C_B_HI_Y << found	<< C_RST << std::endl;

	}
	catch( std::exception const &e)
	{
		std::cout << C_B_HI_R << e.what() << C_RST << std::endl;
	}
	std::cout << C_B_HI_W "\n-------------------------------------------------------------------------- Deque test\n" C_RST;
	std::deque<int>	deq = {-1, 0, 1, 2, 3, 42, 50};
	try
	{
		int num = 42;
		std::cout << "Looking for number:	"	<< C_B_HI_Y << num		<< C_RST << std::endl;
		int found = *easyfind< std::deque<int> >(deq, num);
		std::cout << "Found number:		"		<< C_B_HI_Y << found	<< C_RST << std::endl;
		std::cout << std::endl;

		num = 420;
		std::cout << "Looking for number:	"	<< C_B_HI_Y << num		<< C_RST << std::endl;
		found = *easyfind< std::deque<int> >(deq, num);
		std::cout << "Found number:		"		<< C_B_HI_Y << found	<< C_RST << std::endl;
	}
	catch( std::exception const &e)
	{
		std::cout << C_B_HI_R << e.what() << C_RST << std::endl;
	}
	std::cout << C_B_HI_W "\n-------------------------------------------------------------------------- Array test\n" C_RST;
	std::array<int, 7>	arr = {-1, 0, 1, 2, 3, 42, 50};
	try
	{
		int num = 42;
		std::cout << "Looking for number:	"	<< C_B_HI_Y << num		<< C_RST << std::endl;
		int found = *easyfind< std::array<int, 7> >(arr, num);
		std::cout << "Found number:		"		<< C_B_HI_Y << found	<< C_RST << std::endl;
		std::cout << std::endl;

		num = 420;
		std::cout << "Looking for number:	"	<< C_B_HI_Y << num		<< C_RST << std::endl;
		found = *easyfind< std::array<int, 7> >(arr, num);
		std::cout << "Found number:		"		<< C_B_HI_Y << found	<< C_RST << std::endl;
	}
	catch( std::exception const &e)
	{
		std::cout << C_B_HI_R << e.what() << C_RST << std::endl;
	}
	std::cout << "=====================================================================================\n";
	return (0);
}

