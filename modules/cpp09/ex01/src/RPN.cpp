/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:55:24 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/18 14:02:39 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <regex>
#include <limits>

static void	print_stack(std::stack<int> stack);

int rpn( std::string const &input )
{
	std::stringstream inputStream( input );
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
			try
			{
				operands.push( std::stoi( token ) );
			}
			catch( std::exception const &e )
			{
				std::cerr 
					<< "Error: token overflows int" 
					<< std::endl;
				return (1);
			}
			if (operands.top() < 0 || operands.top() > 9)
			{
				std::cerr 
					<< "invalid operand (all must be between 0 and 9)"
					<< std::endl;
				return (1);
			}
		}
		else if ( token.size() == 1 && std::any_of( supportedOperands.cbegin(), supportedOperands.cend(),
													[ &x = token[0] ]( auto const &y ) { return x == y; }))
		{
			if ( operands.size() < 2)
			{
				std::cerr
					<< "Error: not enough operands in stack" 
					<< std::endl;
				return (1);
			}

			int			lhs;
			int			rhs;
			long long	result;

			result = 0;

			rhs = operands.top();
			operands.pop();
			lhs = operands.top();
			operands.pop();

			switch ( token[0] )
			{
				case '+':
					result = static_cast<long long>( lhs ) + rhs;
					break;
				case '-':
					result = static_cast<long long>( lhs ) - rhs;
					break;
				case '*':
					result = static_cast<long long>( lhs ) * rhs;
					break;
				case '/':
					if (rhs == 0)
					{
						std::cerr
							<< "Error: devision by zero"
							<< std::endl;
						return (1);
					}
					result = lhs / rhs;
					break;

			}
			if ( result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min() )
			{
				std::cerr 
					<< "Error: int overflow during calculation"
					<< std::endl;
				return (1);
					
			}
			++operationCount;
			operands.push(result);
		}
		else
		{
			std::cout
				<< "\'"
				<< token
				<< "\'"
				<< " is not a valid token / number or operator (invalid)"
				<< std::endl;
			return (1);
		}
	}
	if ( operationCount == 0)
	{
		std::cerr
			<< "Error: no operators given"
			<< std::endl;
		return (1);
	}
	if ( operands.size() != 1 )
	{
		std::cerr 
			<< "Error: not enough operators" 
			<< std::endl;
		return (1); 
	}
	print_stack(operands);
	return (0);
}

static void	print_stack(std::stack<int> stack)
{
	std::stack<int> temp_stack = stack;
	while ( !temp_stack.empty() )
	{
		std::cout << temp_stack.top() << std::endl;
		temp_stack.pop();
	}
}
