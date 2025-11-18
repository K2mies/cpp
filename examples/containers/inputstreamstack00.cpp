/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputstreamstack00.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:43:23 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/18 11:43:31 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <regex>

void	print_stack(std::stack<int> stack)
{
	std::stack<int> temp_stack = stack;
	while ( !temp_stack.empty() )
	{
		std::cout << temp_stack.top() << std::endl;
		temp_stack.pop();
	}
}


int main( int argc, char **argv )
{

	if (argc != 2)
	{
		std::cerr << "error" << std::endl;
		return (1);
	}

	std::stringstream inputStream( argv[1] );
	if ( !inputStream )
	{
		std::cerr << "Error: could not open input string stream" << std::endl;
	}

	std::string			token;
	std::regex			numFormat( R"(^[+-]?\d+$)");
	std::string const	supportedOperands = "+-/*";
	std::stack<int>		operands;
	size_t				operationCount = 0;

	while ( inputStream >> token )
	{
		if (std::regex_match (token, numFormat))
		{
			std::cout
				<< "number: "
				<< token
				<< " is a valid number"
				<< std::endl;
			try
			{
				operands.push( std::stoi( token ) );
			}
			catch( std::exception const &e )
			{
				std::cerr << "Error: token overflows int" << std::endl;
				return (1);
			}
		}
		else if ( token.size() == 1 && std::any_of( supportedOperands.cbegin(), supportedOperands.cend(),
													[ &x = token[0] ]( auto const &y ) { return x == y; }))
		{
			std::cout
				<< token
				<< " is a valid operator"
				<< std::endl;
		}
		else
		{
			std::cout
				<< token
				<< " is not a valid number or operator (invalid)"
				<< std::endl;
		}
	}
	print_stack(operands);
	return (0);
}
