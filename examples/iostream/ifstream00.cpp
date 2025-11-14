/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifstream00.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:02:40 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/14 12:24:54 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

int main()
{
   std::string dataFileName = "test.txt";
   std::ifstream dataFile( dataFileName );
   //check if datafile is valid
   if ( !dataFile )
   {
	  std::cout
		 << "Error; "
		 << "could not open datafile"
		 << std::endl;
	  return (1);
   }
   //bookmarks the starting position of hte file
   auto streamStart = dataFile.tellg();
   std::string line;
   
   std::getline(dataFile, line);
   //check for empty file (a single newline also counts)
   if (line.empty() && !dataFile)
   {
	  std::cout
		 << "Error: "
		 << "empty data file"
		 << std::endl;
   }
   //restore stream to start of file
   dataFile.seekg( streamStart );

   size_t	lineCounter = 0;

   while ( std::getline( dataFile, line))
   {
	  ++lineCounter;
	  std::cout 
		 << "line: "
		 << lineCounter
		 << " is: "
		 << line << std::endl;
   }
   return ( 0 );
}
