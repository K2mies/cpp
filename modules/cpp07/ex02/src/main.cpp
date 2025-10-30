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
#include "Array.hpp"
#include <iostream>

int main()
{

	std::cout << "======================================= " C_B_HI_Y "Tests" C_RST " ========================================\n";
	std::cout << C_B_HI_W "\n----------------------------------------------------------------- default constructor\n" C_RST;
	Array<int> arr_a;
	try
	{
	std::cout << arr_a[0] << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << C_B_HI_W "\n--------------------------------------------------------------- parameter constructor\n" C_RST;
	Array<int> arr_b(10);
	try
	{
		for ( size_t i = 0; i < arr_b.size(); i++)
		{
			arr_b[i] = i;
			std::cout << arr_b[i] << std::endl;
		}
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << C_B_HI_W "\n------------------------------------------------------------------------ out of bounds\n" C_RST;
	try
	{
		std::cout << "out of bounds is: " << arr_b[11] << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << C_B_HI_W "\n---------------------------------------------------------------------- copy constructor\n" C_RST;
	Array<unsigned int> arr_c( 10 );
	for ( size_t i = 0; i < arr_c.size(); i++)
		arr_c[i] = i;
	Array<unsigned int> arr_c_copy( arr_c );
	for (size_t i = 0; i < arr_c_copy.size(); ++i)
		std::cout << arr_c_copy[i] << std::endl;

	std::cout << C_B_HI_W "\n-------------------------------------------------------------------------- string array\n" C_RST;
	Array<std::string> arr_d(10);
	std::string msg = "test";
	for (size_t i = 0; i < arr_d.size(); ++i)
		arr_d[i] = msg + " " + std::to_string( i );
	for (size_t i = 0; i < arr_d.size(); ++i)
		std::cout << "\"" <<  arr_d[i] << "\"" << std::endl;
	std::cout << C_B_HI_W "\n--------------------------------------------------------------------- int  pointer test\n" C_RST;
	int	*a = new int();
	std::cout << *a << std::endl;
	return (0);
}

