/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:36:26 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/20 12:40:57 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AForm.hpp"
#include "ansi_colors.hpp"

// ---------------------------------------------------------------- constructors
AForm::AForm(const std::string &name,
	     const std::string &target,
	     const unsigned int gradeToSign,
	     const unsigned int gradeToExec,
	     bool isSigned)
			: _name(name),
			  _target(target),
			  _gradeToSign(gradeToSign),
			  _gradeToExec(gradeToExec),
			  _isSigned(isSigned)
{
	if (_gradeToSign > MIN_GRADE || _gradeToExec > MIN_GRADE)
		throw GradeTooLowException();
	if (_gradeToSign < MAX_GRADE || _gradeToExec < MAX_GRADE)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other)
			: _name(other._name),
			  _gradeToSign(other._gradeToSign),
			  _gradeToExec(other._gradeToExec),
			  _isSigned(other._isSigned){}

// ------------------------------------------------------------ member functions
void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

// ----------------------------------------------------------- getters & setters
const std::string AForm::getName() const
{
	return (this->_name);
}

const std::string AForm::getTarget() const
{
	return (this->_target);
}

unsigned int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

unsigned int AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}
// ------------------------------------------------------------------ exceptions
const char *AForm::GradeTooLowException::what() const noexcept
{
	return (C_HI_R "Forms grade too low!" C_RST);   
}

const char *AForm::GradeTooHighException::what() const noexcept
{
	return (C_HI_R "Forms grade too high!" C_RST);
}

const char *AForm::FormNotSignedException::what() const noexcept
{
	return (C_HI_R "Form not signed!" C_RST);
}

// ---------------------------------------------------------- operator overloads
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Name: "
	<< C_HI_B << form.getName()                                 << C_RST
	<< std::endl
	<< "Target: "
	<< C_HI_Y << form.getTarget()				    << C_RST
	<< std::endl
	<< "Grade to sign: "
	<< C_HI_Y << form.getGradeToSign()			    << C_RST
	<< std::endl
	<< "Grade to execute: "
	<< C_HI_Y << form.getGradeToExec()			    << C_RST
	<< std::endl
	<< "form is "
        << C_HI_R << (form.getIsSigned() ? "signed" : "unsigned")   << C_RST
	<< std::endl;
	return (os);
}
