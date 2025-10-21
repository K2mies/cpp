/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:29:56 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/20 12:35:54 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	public:
	// ---------------------------------------------------------------- constructors
		PresidentialPardonForm() = default;
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &) = delete;
	// ------------------------------------------------------------------ destructor
		~PresidentialPardonForm() = default;
	// --------------------------------------------------- member operator overloads
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &) = delete;
	// ------------------------------------------------------------ member functions
		void					execute(const Bureaucrat &executor) const override;
};

#endif
