/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:46:21 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/24 15:45:23 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <random>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "ansi_colors.hpp"


enum DerivedType : unsigned int
{
	A_type,
	B_type,
	C_type
};

Base	*generate()
{
	std::random_device	rd;
	size_t				r = rd() %3;

	switch (r)
	{
		case A_type:
			return new A();
		case B_type:
			return new B();
		case C_type:
			return new C();
		default:
			return nullptr;
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << C_B_HI_Y << "A" << C_RST << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << C_B_HI_Y << "B" << C_RST << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << C_B_HI_Y << "C" << C_RST << std::endl;
	else
		std::cout << C_B_HI_R << "you wot!?" << C_RST << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << C_B_HI_Y << "A" << C_RST << std::endl;
		return;
	}
	catch(std::exception const &e){}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << C_B_HI_Y << "B" << C_RST << std::endl;
		return;
	}
	catch(std::exception const &e){}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << C_B_HI_Y << "C" << C_RST << std::endl;
		return;
	}
	catch(std::exception const &e){}
	std::cout << "how no!?" << std::endl;
}

int main() 
{
	Base *b = generate();
	std::cout << "Type identified by pointer casting:	";
	identify(b);
	std::cout << "Type identified by reference casting:	";
	identify(*b);
	delete b;
	return (0);
}
