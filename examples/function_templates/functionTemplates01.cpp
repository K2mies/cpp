/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionTemplates00.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:05:22 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/27 11:14:53 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <array>

void	print_array(auto array)
{
	for (auto value : array)
	{
		std::cout << value << ' ';
	}
	std::cout << std::endl;
}

int	main()
{
	std::array<int, 3> my_int_arr = {1, 2, 3};
//	print_array<std::array<int, 3>>(my_int_arr);
	print_array(my_int_arr);

	std::array<float, 3> my_float_arr = {1.1f, 2.2f, 3.3f};
//	print_array<std::array<float, 3>>(my_float_arr);
	print_array(my_float_arr);
	return (0);
}
