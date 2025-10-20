/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:50:17 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/20 11:57:13 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

#define	MAX_GRADE	1
#define	MIN_GRADE	150

class AForm;

class Bureaucrat
{
	public:
	// ---------------------------------------------------------------- constructors
		Bureaucrat();
		Bureaucrat(const std::string &name, unsigned int grade);
		Bureaucrat(const Bureaucrat &other);
	// ------------------------------------------------------------------ destructor
		~Bureaucrat() = default;
	// --------------------------------------------------- member operator overloads
		Bureaucrat &operator=(Bureaucrat const &other) = delete;
	// ------------------------------------------------------------ member functions
		void				executeForm(AForm &form)	const;
		void				signForm(AForm &form)		const;
	// ----------------------------------------------------------- getters & setters
		std::string 		getName()					const;
		unsigned int		getGrade()					const;
	// --------------------------------------------- incramentation & decrementation
		void				incrementGrade();
		void				decrementGrade();
	// ------------------------------------------------------------------ exceptions
		class				GradeTooHighException : public std::exception
		{
			const char *what() const noexcept override;
		};

		class				GradeTooLowException : public std::exception
		{
			const char *what() const noexcept override;
		};
	private:
	// ---------------------------------------------------- private member variables
		const std::string	_name;
		int					_grade;
};

// ----------------------------------------------------------- cout  << overload
std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif
