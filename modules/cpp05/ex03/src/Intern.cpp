/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:07:41 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/21 13:11:29 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ansi_colors.hpp"
#include <iostream>

enum FormType : int
{
	SHRUB,
	ROBO,
	PREZ,
	UNKNOWN,
};

constexpr char const * const formNames[] = 
{
	"shrubbery creation", "robotomy request", "presidential pardon"
};

AForm*	Intern::makeForm(const std::string &formName, const std::string &target) const
{
	FormType type = UNKNOWN;
	for (size_t i = 0; i < sizeof(formNames) / sizeof(formNames[0]); ++i)
	{
		if (formNames[i] == formName)
		{
			type = static_cast<FormType>(i);
			std::cout << "Intern creates "
				  << C_HI_B << formName << C_RST
				  << " form"
				  << std::endl;
			break;
		}
	}
	switch(type)
	{
		case SHRUB:
			return (new ShrubberyCreationForm(target));
		case ROBO:
			return (new RobotomyRequestForm(target));
		case PREZ:
			return (new PresidentialPardonForm(target));
		default:
			std::string msg = formName + " form is not known to the intern";
			std::cout << msg << std::endl;
			throw std::invalid_argument(msg);
	}
}
