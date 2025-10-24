/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:03:20 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/24 11:24:19 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//#include <random>
#include <cstdlib>
#include <ctime>

enum DerivedType : unsigned int
{
	A,
	B,
	C
};

 int	main()
{
	srand(time(NULL));
	int	r = (rand() % 3);
//	std::random_device rd;
//	size_t				r = rd() % 3;

	std::cout << "random number is: " << r << std::endl;
}
