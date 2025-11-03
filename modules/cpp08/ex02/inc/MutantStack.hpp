/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:57:53 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/03 16:23:12 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#ifndef MUTANT_HPP
#define MUTANT_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() = default;
		MutantStack( MutantStack const &);
		~MutantStack() = default;

		MutantStack &operator=( MutantStack const & );

		using cont = typename std::stack<T>::container_type;

		using iterator					= typename cont::iterator;
		using const_iterator			= typename cont::const_iterator;
		using reverse_iterator			= typename cont::reverse_iterator;
		using const_reverse_iterator	= typename cont::const_reverse_iterator;

		iterator				begin();
		iterator				end();
		const_iterator			begin()		const;
		const_iterator			end()		const;

		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin()	const;
		const_reverse_iterator	rend()		const;
		
		const_iterator			cbegin()	const;
		const_iterator			cend()		const;
		const_reverse_iterator	crbegin()	const;
		const_reverse_iterator	crend()		const;
};

#include "MutantStack.tpp"
#endif
