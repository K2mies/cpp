/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:34:50 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/17 12:08:05 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
	// ---------------------------------------------------------------- constructors
		Form();
		Form(const std::string	&name,
			 const unsigned int	gradeToSign,
			 const unsigned int	gradeToExec,
			 bool				isSigned = false);
		Form(const Form &);
	// ------------------------------------------------------------------ destructor
		~Form() = default;
	// --------------------------------------------------- member operator overloads
		Form &operator=(Form const &) = delete;
	// ------------------------------------------------------------ member functions
		void					beSigned(const Bureaucrat &);
	// ----------------------------------------------------------- getters & setters
		const std::string		getName()			const;
		unsigned int		getGradeToSign()	const;
		unsigned int		getGradeToExec()	const;
		bool					getIsSigned()		const;
	// ------------------------------------------------------------------ exceptions
		class					GradeTooHighException : public std::exception
		{
			const char *what() const noexcept override;
		};

		class					GradeTooLowException : public std::exception
		{
			const char *what() const noexcept override;
		};
	private:
	// ---------------------------------------------------- private member variables
		const std::string		_name;
		const unsigned int		_gradeToSign;
		const unsigned int		_gradeToExec;
		bool					_isSigned = false;	
};

std::ostream &operator<<(std::ostream &, const Form &);

#endif
