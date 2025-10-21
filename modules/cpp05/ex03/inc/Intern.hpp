#pragma once

#ifndef	INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

class AForm;

class Intern
{
	public:
	// ---------------------------------------------------------------- constructors
	Intern() = default;
	Intern(const Intern &) = default;
	// ------------------------------------------------------------------ destructor
	~Intern() = default;
	// --------------------------------------------------- member operator overloads
	Intern &operator=(const Intern &) = default;
	// ------------------------------------------------------------ member functions
	AForm*	makeForm(const std::string &formName, const std::string &target ) const;
};

#endif
