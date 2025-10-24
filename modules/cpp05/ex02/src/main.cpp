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
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ansi_colors.hpp"

int	main()
{
	srand(time(0)); // needed for random number generator in RobotomyRequestForm.cpp
	std::cout << "===================================== " C_B_HI_Y "Shrubbery" C_RST " ======================================\n";
	std::cout << C_B_HI_W "\n------------------------------------------------------------------ shrubbery creation\n" C_RST;
	ShrubberyCreationForm	shrub("Hive");
	std::cout << shrub;

	std::cout << C_B_HI_W "\n------------------------------------------------------------------------ sign failure\n" C_RST;
	Bureaucrat blobby_a("Mr Blobby A", 150);
	std::cout << blobby_a;
	blobby_a.signForm(shrub);
	blobby_a.executeForm(shrub);
	std::cout << std::endl;
	std::cout << C_B_HI_W "\n------------------------------------------------------------------------ sign success\n" C_RST;
	Bureaucrat blobby_b("Mr Blobby B", shrub.getGradeToSign());
	std::cout << blobby_b;
	blobby_b.signForm(shrub);
	blobby_b.executeForm(shrub);
	std::cout << std::endl;
	std::cout << C_B_HI_W "\n------------------------------------------------------------------------ exec success\n" C_RST;
	Bureaucrat blobby_c("Mr Blobby C", shrub.getGradeToExec());
	std::cout << blobby_c;
	blobby_c.signForm(shrub);
	blobby_c.executeForm(shrub);
	std::cout << std::endl;

	std::cout << "====================================== " C_B_HI_Y "Robotamy" C_RST " ======================================\n";
	std::cout << C_B_HI_W "\n------------------------------------------------------------------- robotamy creation\n" C_RST;
	RobotomyRequestForm	robo("Robotomy");
	std::cout << robo;
	std::cout << C_B_HI_W "\n------------------------------------------------------------------------ sign failure\n" C_RST;
	Bureaucrat blobby_d("Mr Blobby D", 150);
	std::cout << blobby_d;
	blobby_d.signForm(robo);
	blobby_d.executeForm(robo);
	std::cout << std::endl;
	std::cout << C_B_HI_W "\n------------------------------------------------------------------------ sign success\n" C_RST;
	Bureaucrat blobby_e("Mr Blobby E", robo.getGradeToSign());
	std::cout << blobby_e;
	blobby_e.signForm(robo);
	blobby_e.executeForm(robo);
	std::cout << std::endl;
	std::cout << C_B_HI_W "\n------------------------------------------------------------------------ exec success\n" C_RST;
	Bureaucrat blobby_f("Mr Blobby F", robo.getGradeToExec());
	std::cout << blobby_f;
	blobby_f.signForm(robo);
	blobby_f.executeForm(robo);
	std::cout << std::endl;

	std::cout << "================================== " C_B_HI_Y "Presidential" C_RST " ======================================\n";
	std::cout << C_B_HI_W "\n------------------------------------------------------------------- robotamy creation\n" C_RST;
	RobotomyRequestForm	pres("Presidential");
	std::cout << pres;
	std::cout << C_B_HI_W "\n------------------------------------------------------------------------ sign failure\n" C_RST;
	Bureaucrat blobby_g("Mr Blobby G", 150);
	std::cout << blobby_g;
	blobby_d.signForm(pres);
	blobby_d.executeForm(pres);
	std::cout << std::endl;
	std::cout << C_B_HI_W "\n------------------------------------------------------------------------ sign success\n" C_RST;
	Bureaucrat blobby_h("Mr Blobby H", pres.getGradeToSign());
	std::cout << blobby_h;
	blobby_h.signForm(pres);
	blobby_h.executeForm(pres);
	std::cout << std::endl;
	std::cout << C_B_HI_W "\n------------------------------------------------------------------------ exec success\n" C_RST;
	Bureaucrat blobby_i("Mr Blobby I", pres.getGradeToExec());
	std::cout << blobby_i;
	blobby_i.signForm(pres);
	blobby_i.executeForm(pres);
	std::cout << std::endl;
	return (0);
}
