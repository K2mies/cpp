/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:36:42 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/27 15:49:13 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	public:
	// ---------------------------------------------------------------- constructors
		Array();
		Array(size_t n);
		Array(Array const &);
	// ------------------------------------------------------------------ destructor
		~Array();	
	// --------------------------------------------------- member operator overloads
		Array	&operator=(Array const &);
		T		&operator[](size_t idx) const;
	// ------------------------------------------------------------ member functions
		size_t	size() const;
	private:
	// ---------------------------------------------------- private member variables
		size_t	_len = 0;
		T		*_arr = nullptr;
};

#include "Array.tpp"
