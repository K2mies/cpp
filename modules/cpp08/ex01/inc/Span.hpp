/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:18:17 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/31 11:41:53 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#ifndef	SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_ints;

	public:
		Span() = delete;
		Span( unsigned int N );
		~Span() = default;

		Span			&operator=(Span const &);
	
		void			print()			const;
		void			addNumber( int num );

		unsigned int	shortestSpan()	const;
		unsigned int	longestSpan()	const;

		class	sizeReachedException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};
		class	noSpanFoundException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};
};
#endif
