/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:24:08 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/20 12:29:49 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	public:
	// ---------------------------------------------------------------- constructors
		RobotomyRequestForm() = default;
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &) = delete;
	// ------------------------------------------------------------------ destructor
		~RobotomyRequestForm() = default;
	// --------------------------------------------------- member operator overloads
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &) = delete;
	// ------------------------------------------------------------ member functions
		void				execute(const Bureaucrat &executor) const override;
};

#endif
