/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbervalidation00.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:12:57 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/14 14:31:05 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <regex>


int main()
{
	std::string token = "-9";
	std::regex	numFormat( R"(^[+-]?\d+$)");

	if (std::regex_match ( token, numFormat) )
	{
		std::cout << "token is valid number format" << std::endl;

	}
	else 
	{
		std::cout << "token is not a valid number format" << std::endl;
	}
	return (0);
}
