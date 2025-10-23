/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:18:47 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/23 15:21:44 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Data.hpp"

Data:: Data(const Data &other) : x(other.x) {}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		x = other.x;
	}
	return (*this);
}
