/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:40:27 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/27 11:46:09 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ansi_colors.hpp>
#include "iter.hpp"
#include <string>
#include <iostream>


int main()
{
	int int_arr[] = {1, 2, 3, 4, 5};
	float float_arr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

	std::cout << "=================================== " C_B_HI_Y "Print int array" C_RST " ==================================\n";
	size_t	int_n = sizeof(int_arr) / sizeof(int_arr[0]);
	iter(&int_arr[0], int_n, printArrMember);
	std::cout << std::endl;

	std::cout << "================================== " C_B_HI_Y "Print float array" C_RST " =================================\n";
	size_t float_n = sizeof(float_arr) / sizeof(float_arr[0]);
	iter(&float_arr[0], float_n, printArrMember);
	std::cout << std::endl;

	std::cout << "=================================== " C_B_HI_Y "Double int array" C_RST " =================================\n";
	iter(&int_arr[0], int_n, doubleMember);
	iter(&int_arr[0], int_n, printArrMember);
	std::cout << std::endl;

	std::cout << "================================== " C_B_HI_Y "Double float array" C_RST " ================================\n";
	iter(&float_arr[0], float_n, doubleMember);
	iter(&float_arr[0], float_n, printArrMember);
	std::cout << std::endl;
	std::cout << "===================================== " C_B_HI_Y "Const test" C_RST " =====================================\n";
	const int const_arr[] = {1 ,2 ,3 ,4, 5};
	size_t const_n = sizeof(const_arr) / sizeof(const_arr[0]);
//	iter(&const_arr[0], const_n, doubleMember); // will cause a compiler error
	iter(&const_arr[0], const_n, printArrMember);
	return (0);
}
