/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:16:28 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/16 13:34:36 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ansi_colors.hpp"


// ----------------------------------------------------------- getters & setters
std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}
// --------------------------------------------- incramentation & decrementation
void	Bureaucrat::incrementGrade()
{
	if (_grade >= MIN_GRADE)
		throw GradeTooLowException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade <= MAX_GRADE)
		throw GradeTooHighException();
	_grade++;
}

// ------------------------------------------------------------------ exceptions
const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return (C_HI_R "Grade too low!" C_RST);
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return (C_HI_R "Grade too high!" C_RST);
}

// ---------------------------------------------------------------- constructors
Bureaucrat::Bureaucrat(): _name("unnamed"), _grade(MIN_GRADE) {};

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _name(name), _grade(grade)
{
	if (grade < MAX_GRADE)
		throw	GradeTooHighException();
	if (grade > MIN_GRADE)
		throw	GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {};

// ---------------------------------------------------------- operator overloads
std::ostream &operator<<(std::ostream &os, const Bureaucrat &current)
{
	os << C_HI_P << current.getName() << "'s" << C_RST << " Bureaucrat grade is: " << C_B_HI_Y << current.getGrade() << C_RST << std::endl;
	return (os);
}
