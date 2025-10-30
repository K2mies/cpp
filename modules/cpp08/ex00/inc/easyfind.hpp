/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:42:02 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/30 12:59:46 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include <algorithm>

class notFoundException : public std::exception
{
	public:
		const char *what() const noexcept override
		{
			return ("Element not found in container");
		}
};

template<typename T>
auto easyfind( T &container, int num )
{
	auto iter = std::find(container.begin(), container.end(), num);

	if (iter == container.end())
		throw(notFoundException());
	return (iter);
}
