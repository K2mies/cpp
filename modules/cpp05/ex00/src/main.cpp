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

#include "Bureaucrat.hpp"
#include "ansi_colors.hpp"

int	main()
{

	std::cout << "===================================== " C_B_HI_Y "Wrong Grade" C_RST " ===================================\n";
	try
	{
		Bureaucrat bureaucrat_a("other", 151);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "============================== " C_B_HI_Y "Right Grade Wrong increment" C_RST " ==========================\n";
	std::cout << C_B_HI_W "\n----------------------------------------------------------------- Wrong decrement\n" C_RST;
	try
	{
		Bureaucrat bureaucrat_b("other", 150);
		bureaucrat_b.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << C_B_HI_W "\n----------------------------------------------------------------- Wrong increment\n" C_RST;
	try
	{
		Bureaucrat bureaucrat_c("other", 1);
		bureaucrat_c.decrementGrade();
		bureaucrat_c.incrementGrade();
		bureaucrat_c.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "================================= " C_B_HI_Y "Working Bureaucrat" C_RST " ================================\n";
	try
	{
		Bureaucrat bureaucrat_d("Mr Blobby", 1);
		std::cout << bureaucrat_d << std::endl;
		bureaucrat_d.incrementGrade();
		std::cout << bureaucrat_d << std::endl;
		bureaucrat_d.incrementGrade();
		std::cout << bureaucrat_d << std::endl;
		bureaucrat_d.decrementGrade();
		std::cout << bureaucrat_d << std::endl;

		Bureaucrat bureaucrat_e(bureaucrat_d);
		std::cout << "I am a copy of bureaucrat_d: " << bureaucrat_e << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
