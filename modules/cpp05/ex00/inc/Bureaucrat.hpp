/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:16:35 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/16 13:52:08 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define	MAX_GRADE	1
#define	MIN_GRADE	150

class Bureaucrat
{
	private:
	// ---------------------------------------------------- private member variables
		const std::string	_name;
		int					_grade;
	public:
	// ----------------------------------------------------------- getters & setters
		std::string 		getName() 	const;
		unsigned int		getGrade() 	const;
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
	// ---------------------------------------------------------------- constructors
		Bureaucrat();
		Bureaucrat(const std::string &name, unsigned int grade);
		Bureaucrat(const Bureaucrat &other);
	// ------------------------------------------------------------------ destructor
		~Bureaucrat() = default;
	// --------------------------------------------------- member operator overloads
		Bureaucrat &operator=(Bureaucrat const &other) = delete;
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif
