/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:34:20 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/20 15:48:08 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// ---------------------------------------------------------------- constructors
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
		 : AForm("robotomy request", target, 72, 45, false) {}

// ------------------------------------------------------------ member functions
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw Bureaucrat::GradeTooLowException();
	std::cout << "* DRRRRNGGGG PSHHHH CLANG CLANG BZZZZ WWHOOOOWSZZ *\n";
	srand(time(0));
	if (std::rand() % 2 == 0)
	{
		std::cout << getTarget() << " has been succesfully Robotomized." << std::endl;
	}
	else
	{
		std::cout << "The robotomy failed, " << getTarget() << "has died. bummer" << std::endl;
	}
}
