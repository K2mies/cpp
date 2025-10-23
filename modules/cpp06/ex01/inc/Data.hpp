/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:19:18 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/23 11:28:44 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#ifndef DATA_HPP
#define DATA_HPP

class Data
{
	public:
		Data() = default;
		Data(const Data &);
		~Data() = default;
		
		Data &operator=(const Data &);
		
		int	x = 42;
};
#endif
