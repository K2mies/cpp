/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:42:58 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/27 15:49:10 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// ---------------------------------------------------------------- constructors
template<typename T>
Array<T>:: Array()
	: _len(0), _arr(new T[0]) {}

template<typename T>
Array<T>:: Array(size_t n)
	: _len(n), _arr(new T[n]) {}

template<typename T>
Array<T>:: Array( Array<T> const &other)
	: _len( other._len), _arr(new T[other._len])
{
	for (size_t i = 0; i < _len; ++i)
		_arr[i] = other._arr[i];
}
// ------------------------------------------------------------------ destructor
template<typename T>
Array<T>:: ~Array()
{
	delete[] _arr;
}

// --------------------------------------------------- member operator overloads
template<typename T>
Array<T>	&Array<T>:: operator=( Array<T> const &other)
{
	if (this != &other)
	{
		if (_len != other._len)
		{
			delete[] _arr;
			_len = other._len;
			_arr = new T[_len];;
		}
		for (size_t i = 0; i < _len; ++i)
		{
			_arr[i] = other._arr[i];
		}
	}
	return (*this);
}

template<typename T>
T	&Array<T>:: operator[](size_t idx) const
{
	if (idx >= _len)
	{
		throw std::out_of_range
		(
			"Array: index " + std::to_string(idx) + " out of range, "
			+ "array size: " + std::to_string(_len)
		);
	}
	return _arr[idx];
}

// ------------------------------------------------------------ member functions
template<class T>
size_t	Array<T>:: size() const
{
	return (_len);
}
