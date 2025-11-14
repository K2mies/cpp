/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputstream00.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:31:25 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/14 15:24:16 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <regex>
#include <limits>

int main(int argc, char **argv)
{
   if (argc != 2)
   {
      std::cout << "error" << std::endl;
      return (1);
   }

   std::stringstream inputStream( argv[1] );
   if ( !inputStream)
   {
      std::cerr << "Error: could not open input string stream" << std::endl;
      return (1);
   }
   std::string token;

   while ( inputStream >> token)
   {
      std::cout << "token is: " << token << std::endl;
   }

   return (0);
}
