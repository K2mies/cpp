/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack00.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:13:19 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/14 14:12:37 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <stack>

int main()
{
	std::stack<int> stack;

	//push 10 elements into the stack
	for (int i = 0; i < 10; i++)
		stack.push(i);
	stack.push(20);
	//print out stack
	std::stack<int> temp_stack = stack;
	while ( !temp_stack.empty() )
	{
		std::cout << temp_stack.top() << std::endl;
		temp_stack.pop();
	}

	temp_stack = stack;
	int	lhs;
	int	rhs;

	rhs = temp_stack.top();
	temp_stack.pop();
	lhs = temp_stack.top();
	temp_stack.pop();

	std::cout << "rhs = " << rhs << std::endl << "lhs = " << lhs << std::endl;
	return ( 0 );
}
