/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:10:48 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/20 12:13:11 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	public:
	// ---------------------------------------------------------------- constructors
		ShrubberyCreationForm() = delete;
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &) = delete;
	// ------------------------------------------------------------------ destructor
		~ShrubberyCreationForm() = default;
	// --------------------------------------------------- member operator overloads
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &) = delete;
	// ------------------------------------------------------------ member functions
		void					execute(const Bureaucrat &executor) const override;
};

#endif
