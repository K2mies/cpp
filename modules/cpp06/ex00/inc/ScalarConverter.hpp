#pragma once

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &) = delete;
		~ScalarConverter() = default;

		ScalarConverter &operator=(const ScalarConverter &) = delete;

		static void convert (const std::string &str);
};

#endif
