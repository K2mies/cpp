/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:24:37 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/28 12:33:04 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"
#include "ansi_colors.hpp"

void	subject_main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	subject_main_with_list()
{
	std::list<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}
int main()
{
	std::cout << "================================== " C_B_HI_Y "Main Subject Test" C_RST " =================================\n";
	std::cout << C_B_HI_W "\n------------------------------------------------------------------- with Mutant Stack\n" C_RST;
	subject_main();
	std::cout << C_B_HI_W "\n--------------------------------------------------------------------------- with list\n" C_RST;
	subject_main_with_list();
	return (0);
}

