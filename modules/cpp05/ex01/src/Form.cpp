/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:12:12 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/17 13:14:40 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.hpp"
#include "ansi_colors.hpp"

// ---------------------------------------------------------------- constructors
Form::Form(): _name("Generic form"), _gradeToSign(150), _gradeToExec(150){}

Form::Form(const std::string &name, 
		   const unsigned int gradeToSign,
		   const unsigned int gradeToExec,
		   bool isSigned)
			: _name(name),
			  _gradeToSign(gradeToSign),
			  _gradeToExec(gradeToExec),
			  _isSigned(isSigned)
{
	if (_gradeToSign > MIN_GRADE || _gradeToExec > MIN_GRADE)
		throw GradeTooLowException();
	if (_gradeToSign < MAX_GRADE || _gradeToExec < MAX_GRADE)
		throw GradeTooHighException();
}

Form::Form(const Form &other)
			: _name(other._name),
			  _gradeToSign(other._gradeToSign),
			  _gradeToExec(other._gradeToExec),
			  _isSigned(other._isSigned){}

// ------------------------------------------------------------ member functions
void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

// ----------------------------------------------------------- getters & setters
const std::string Form::getName() const
{
	return (this->_name);
}

const	unsigned int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

const unsigned int Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}
// ------------------------------------------------------------------ exceptions
const char *Form::GradeTooLowException::what() const noexcept
{
	return (C_HI_R "Forms grade too low!" C_RST);   
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return (C_HI_R "Forms grade too high!" C_RST);
}

// ---------------------------------------------------------- operator overloads
std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os  << "Form "
        << C_HI_B << form.getName()                                 << C_RST
	    << " is "
        << C_HI_R << (form.getIsSigned() ? "signed" : "unsigned")   << C_RST
	    << ", grade to sign: "
        << C_HI_Y << form.getGradeToSign()                          << C_RST
	    << ", grade to execute: "
        << C_HI_Y << form.getGradeToExec()                          << C_RST
	    << std::endl;
	return (os);
}
