/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:49:08 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/20 15:34:09 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ansi_colors.hpp"

int	main()
{
	srand(time(0)); // needed for random number generator in RobotomyRequestForm.cpp
	Intern intern;
	std::cout << "======================================== " C_B_HI_Y "Intern" C_RST " ======================================\n";
	std::cout << C_B_HI_W "\n------------------------------------------------------------------ shrubbery creation\n" C_RST;
	try
	{
		auto form = intern.makeForm("shrubbery creation", "shrubbery");
		std::cout << std::endl;
		std::cout << *form;
		delete form;
	}
	catch(std::exception &e){}
	std::cout << C_B_HI_W "\n-------------------------------------------------------------------- robotomy request\n" C_RST;
	try
	{
		auto form = intern.makeForm("robotomy request", "robotomy");
		std::cout << std::endl;
		std::cout << *form;
		delete form;
	}
	catch(std::exception &e){}
	std::cout << C_B_HI_W "\n----------------------------------------------------------------- presidential pardon\n" C_RST;
	try
	{
		auto form = intern.makeForm("presidential pardon", "president");
		std::cout << std::endl;
		std::cout << *form;
		delete form;
	}
	catch(std::exception &e){}
	return (0);
}
