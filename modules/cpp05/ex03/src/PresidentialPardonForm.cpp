/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:48:15 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/20 15:54:11 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// ---------------------------------------------------------------- constructors
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
		     : AForm("presidential pardon", target, 25, 5, false){}

// ------------------------------------------------------------ member functions
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw Bureaucrat::GradeTooLowException();
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox. " 
		  << std::endl;
}
