/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:30:19 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/20 11:50:03 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
	// ---------------------------------------------------------------- constructors
		AForm() = delete;
		AForm(const std::string		&name,
			  const std::string		&target,
			  const unsigned int	gradeToSign,
			  const unsigned int	gradeToExec,
			  bool					isSigned = false);
		AForm(const AForm &);
	// ------------------------------------------------------------------ destructor
		virtual ~AForm() = default;
	// --------------------------------------------------- member operator overloads
		AForm &operator=(AForm const &) = delete;
	// ------------------------------------------------------------ member functions
		virtual void 			execute(Bureaucrat const &executor) const = 0;
		void					beSigned(const Bureaucrat &);
	// ----------------------------------------------------------- getters & setters
		const std::string		getName()			const;
		const std::string		getTarget()			const;
		const unsigned int		getGradeToSign()	const;
		const unsigned int		getGradeToExec()	const;
		bool					getIsSigned()		const;
	// ------------------------------------------------------------------ exceptions
		class					GradeTooHighException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};

		class					GradeTooLowException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};
		
		class					FormNotSignedException : public std::exception
		{
			public:
				const char *what() const noexcept override;

		};
	private:
	// ---------------------------------------------------- private member variables
		const std::string		_name;
		const std::string		_target;
		const unsigned int		_gradeToSign;
		const unsigned int		_gradeToExec;
		bool					_isSigned = false;	
};
// ----------------------------------------------------------- cout  << overload
std::ostream &operator<<(std::ostream &, const AForm &);

#endif
