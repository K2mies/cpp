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

int main()
{

	std::cout << "======================================= " C_B_HI_Y "Tests" C_RST " ========================================\n";
	std::cout << C_B_HI_W "\n----------------------------------------------------------------- default constructor\n" C_RST;
	Array<int> arr;
	try
	{
	std::cout << arr[0] << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

