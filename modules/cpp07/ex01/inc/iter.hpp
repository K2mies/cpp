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

#ifndef ITER_HPP
#define	ITER_HPP

#include "ansi_colors.hpp"
#include <iostream>
#include <functional>

template <typename T>
void	iter(T *arrayAddress, size_t len, void(*func)(T&))
{
	for (size_t i = 0; i < len; i++)
		func(arrayAddress[i]);
}

template <typename T>
void	printArrMember(T &member)
{
	std::cout << C_B_HI_Y << member << C_RST << ' ';
}

template <typename T>
void	doubleMember(T &member)
{
	member *= 2;
}

#endif
