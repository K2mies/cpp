/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:28:24 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/31 16:40:11 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <algorithm>
#include <numeric>
#include <iostream>
#include "Span.hpp"
#include "ansi_colors.hpp"

// ---------------------------------------------------------------- constructors
Span::Span(unsigned int N)
	: _N( N ){}

// ---------------------------------------------------------- operator overloads
Span	&Span:: operator=( Span const & other )
{
	if (this != &other)
		_ints = other._ints;
	return (*this);
}
// ------------------------------------------------------------ member functions

void	Span:: print() const
{
	if ( _ints.empty() )
	{
		std::cout << "Empty span" << std::endl;
		return ;
	}
	for ( auto const &i : _ints )
	  std::cout << i << " ";
	std::cout << std::endl;
}

void	Span::addNumber ( int num )
{
	if (_ints.size() >= _N)
		throw sizeReachedException();
	_ints.push_back( num );
}

unsigned int Span::shortestSpan() const
{
	if (_ints.size() < 2)
		throw noSpanFoundException();

	std::vector<int>			sorted( _ints );
	std::vector<unsigned int>	spans( _N, 0 );

	std::sort( sorted.begin(), sorted.end() );
	std::adjacent_difference( sorted.begin(), sorted.end(), spans.begin() );

	return (*std::min_element( spans.begin() + 1, spans.end() ));
}

unsigned int	Span::longestSpan() const
{
	if (_ints.size() < 2)
		throw noSpanFoundException();

	int const max = *std::max_element( _ints.begin(), _ints.end() );
	int const min = *std::min_element( _ints.begin(), _ints.end() );

	return ( max - min);
}

// ------------------------------------------------------------------ exceptions
const char *Span::sizeReachedException::what() const noexcept
{
	return (C_B_HI_R "size limit reached" C_RST);
}

const char *Span::noSpanFoundException::what() const noexcept
{
	return (C_B_HI_R "not enough numbers" C_RST);
}
