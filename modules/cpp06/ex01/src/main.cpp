/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:24:17 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/23 15:36:47 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ansi_colors.hpp"
#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main()
{
	Data	d;
	Data	*ptr = &d;

	std::cout << "================================== " C_B_HI_Y "Pre Serialization" C_RST " =================================\n";
	std::cout << "ptr:		" << C_B_HI_B << ptr << C_RST << std::endl;
	std::cout << "ptr->x:		" << C_B_HI_Y << ptr->x << C_RST << std::endl;\

	ptr = Serializer::deserialize(Serializer::serialize(&d));

	std::cout << "================================= " C_B_HI_Y "Post Serialization" C_RST " =================================\n";
	std::cout << "ptr:		" << C_B_HI_B << ptr << C_RST << std::endl;
	std::cout << "ptr->x:		" << std::dec << C_B_HI_Y << ptr->x << C_RST << std::endl;
	return (0);
}
