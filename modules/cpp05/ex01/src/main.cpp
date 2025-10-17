/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:35:13 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/16 13:56:59 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ansi_colors.hpp"

int	main()
{

//	std::cout << "===================================== " C_B_HI_Y "Wrong Grade" C_RST " ===================================\n";
//	std::cout << C_B_HI_W "\n----------------------------------------------------------------- Wrong decrement\n" C_RST;

	std::cout << "=================================== " C_B_HI_Y "Constructors" C_RST " ====================================\n";
	std::cout << C_B_HI_W "\n----------------------------------------------------------------- default consturctor\n" C_RST;
	Form	test_a;
	std::cout << test_a;
	std::cout << C_B_HI_W "\n--------------------------------------------------------------- parameter consturctor\n" C_RST;
	Form	test_b("Test Form", 150, 150);
	std::cout << test_b;
	std::cout << C_B_HI_W "\n-------------------------------------------------------------------- copy consturctor\n" C_RST;
	Form	org("OG", 1, 1);
	Form	copy(org);
	std::cout << copy;
	std::cout << std::endl;
	std::cout << "====================================== " C_B_HI_Y "Getters" C_RST " ======================================\n";
	Form	test_c("test", 123, 111);
	std::cout << "Form's name:			" << test_c.getName()			<< std::endl;
	std::cout << "Form's grade to sign:		" << test_c.getGradeToSign()	<< std::endl;
	std::cout << "Form's grade to execute:	" << test_c.getGradeToExec()	<< std::endl;
	std::cout << "Form's signed state:		" << test_c.getIsSigned()		<< std::endl;
	Bureaucrat bur_a("Test Bur", 1);
	bur_a.signForm(test_c);
	std::cout << "Form's signed state:		" << (test_c.getIsSigned() ? "true" : "false") << std::endl;
	std::cout << "====================================== " C_B_HI_Y "Signing" C_RST " ======================================\n";
	std::cout << C_B_HI_W "\n------------------------------------------------------------------------------ to low\n" C_RST;
	try
	{
		Form	test_d("easy", 151, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << C_B_HI_W "\n----------------------------------------------------------------------------- to high\n" C_RST;
	try
	{
		Form	test_e("easy", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << C_B_HI_W "\n-------------------------------------------------------------------- cannot be signed\n" C_RST;
	Bureaucrat	blobby_a("Mr Blobby", 150);
	Form		test_f("Sign me please", 149, 149);
	blobby_a.signForm(test_f);
	std::cout << C_B_HI_W "\n----------------------------------------------------------------------- can be signed\n" C_RST;
	Bureaucrat	blobby_b("Mr Blobby", 149);
	Form		test_e("Sign me please", 150, 150);
	blobby_b.signForm(test_e);
	return (0);
}
