/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:24:28 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/27 11:45:39 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#ifndef WHATEVER_HPP
#define	WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	&min(T &a, T &b)
{
	return((a < b) ? a : b);
}

template<typename T>
T	&max(T &a, T &b)
{
	return ((a > b) ? a : b);
}

#endif
