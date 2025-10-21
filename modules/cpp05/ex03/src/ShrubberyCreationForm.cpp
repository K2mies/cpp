/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:45:43 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/20 14:44:28 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

const std::string shrubbery = "SHUBSHUBSHUBSHUBSHUBSHUBSHUBSHUBSHUBSHUBSHUB";

// ---------------------------------------------------------------- constructors
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
			: AForm("shrubbery creation", target, 145, 137){}

// ------------------------------------------------------------ member functions
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw Bureaucrat::GradeTooLowException();
	std::ofstream	output(getTarget() + "_shrubbery");
	if (!output)
		throw std::runtime_error("ERROR: couldn't open file for shrubbery writing");
	output << shrubbery;
}
