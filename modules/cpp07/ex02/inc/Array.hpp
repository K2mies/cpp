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

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Array.tpp"
#include <iostream>

template <typename T>
class Array
{
	private:
		T		*_array;
		size_t	_length;
	public:
		Array();
		Array(unsigned int);
		Array(const Array<T>&);
		Array<T> &operator=(const Array<T>&);
		~Array();
		
		T& operator[](size_t);
		const T& operator[](size_t) const;

		size_t	size() const;
};

#endif
