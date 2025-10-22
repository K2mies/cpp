/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:05:12 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/22 15:47:28 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScalarConverter.hpp"
#include "ansi_colors.hpp"
#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip>

enum LiteralType : unsigned int
{
	UNKNOWN,
	CHAR,
	INT,
	FLOAT,
	DOUBLE, 
};

char	c = '\0',	*cPtr = nullptr;
int		i = +0,		*iPtr = nullptr;
float	f = 0.f,	*fPtr = nullptr;
double	d = -.0,	*dPtr = nullptr;

static LiteralType	checkLiteralType(const std::string &str);
static bool			isCharLiteral(const std::string &str);
static bool			isIntLiteral(const std::string &str);
static bool			isFloatLiteral(const std::string &str);
static bool			isDoubleLiteral(const std::string &str);
static void			convertChar(const std::string &str);
static void			convertInt(const std::string &str);
static void			convertFloat(const std::string &str);
static void			convertDouble(const std::string &str);

void	ScalarConverter::convert(const std::string &str)
{
	static_assert(std::numeric_limits<float>::is_iec559, "IEE 754 required for nan and infinity");
	LiteralType type = checkLiteralType(str);
	switch(type)
	{
		case CHAR:
			convertChar(str);
			break;
		case INT:
			convertInt(str);
			break;
		case FLOAT:
			convertFloat(str);
			break;
		case DOUBLE:
			convertDouble(str);
			break;
		default:
			std::cout << C_HI_R << "Not a valid literal" << C_RST << std::endl;
			return;	
	}
	std::cout << "Char: ";
	if (cPtr && std::isprint(c))
		std::cout << c << std::endl;
	else if (cPtr && c >= 0 && c <= 127)
		std::cout << C_HI_Y << "Non displayable" << C_RST << std::endl;
	else
		std::cout << C_HI_R << "Imposerbru!" << C_RST << std::endl;
	std::cout << "Int: ";
	if (iPtr)
		std::cout << i << std::endl;
	else
		std::cout << C_HI_R << "Imposerbru!" << C_RST << std::endl;
	std::cout << "Float: ";
	if (fPtr)
		std::cout << std::fixed << std::setprecision(1) << f << "f\n";
	else
		std::cout << C_HI_R << "Imposerbru!" << C_RST << std::endl;
	std::cout << "Double: ";
	if (dPtr)
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	else
		std::cout << C_HI_R << "Imposerbru!" << C_RST << std::endl;
}

/**
 *	checks which literal type to deal with
 */
static LiteralType checkLiteralType(const std::string &str)
{
	if (str.empty())
		return UNKNOWN;
	if (isCharLiteral(str))
		return CHAR;
	if (isIntLiteral(str))
		return INT;
	if (isFloatLiteral(str))
		return FLOAT;
	if (isDoubleLiteral(str))
		return DOUBLE;
	return UNKNOWN;
}

/**
*	check for Valid character literals: also if character
*	is inside  single quotes ie: '1' it will be treated
*	as a character and not say an integer scalar etc.
*/
static bool isCharLiteral(const std::string &str)
{
	if (str.size() > 3 || str.size() == 2)
		return false;
	if (	str.size() == 3
			&& str[0] == '\''
			&& str[2] == '\''
			&& (str[1] >= 0 && str[1] <= 127)
		)
		return true;
	if (	str.size() == 1
			&& !std::isdigit(str[0])
			&& (str[0] >= 0 && str[0] <= 127)
		)
		return true;
	return false;
}

/**
*	check for Valid int literals includes use of both
*	+ / - signs respectivley.
*/
static bool	isIntLiteral(const std::string &str)
{
	auto i = str.begin();
	if (*i == '+' || *i == '-')
		i++;
	if (i == str.end() || !std::isdigit(*(i++)))
		return false;
	for (; i != str.end(); ++i)
	{
		if (!std::isdigit(*i))
			return false;
	}
	try
	{
		std::stoi(str);
	}
	catch(const std::exception &e)
	{
		return false;
	}
	return true;
}

/**
*	check for valid double literal including both whole
*	and fractional parts
*/

static bool isDoubleLiteral(const std::string &str)
{
	bool	hasWholePart		= false;
	bool	hasFractionalPart	= false;	
	auto	i					= str.begin();
	if (*i == '+' || *i == '-')
		++i;
	auto 	rest = std::string(i, str.end());
	if (rest == "inf" || str == "nan")
		return true;
	if (std::isdigit( * i))
		hasWholePart = true;
	while (i != str.end() && std::isdigit(*i))
		++i;
	if (i == str.end() || *i != '.') // if no decimal '.' found then is not a double
		return false;
	++i;
	if ( i != str.end() && std::isdigit(*i))
		hasFractionalPart = true;
	while (i != str.end() && std::isdigit(*i))
		++i;
	// number must end and have digits either side of the dots
	if (i != str.end() || (!hasWholePart && !hasFractionalPart))
		return false;
	try
	{
		std::stod(str);
	}
	catch(const std::exception &e)
	{
		return false;
	}
	return true;
}

/**
*	checks for valid float literals, must end in f
*/
static bool isFloatLiteral(const std::string &str)
{
	if (*(str.end() - 1) != 'f')
		return false;
	auto doublePart = std::string(str.begin(), str.end() - 1); // Cuts off the 'f'
	if (!isDoubleLiteral(doublePart)) // checks if valid double after 'f' is cut off
		return false;
	try
	{
		std::stof(str);// Does this number fit into a float?
	}
	catch(const std::exception &e)
	{
		return false;
	}
	return true;
}

static void	convertChar(const std::string &str)
{
	if (str.size() == 3)
		c = str[1];
	else
		c = str[0];
	cPtr = &c;
	i = static_cast<int>(c);
	iPtr = &i;
	f = static_cast<float>(c);
	fPtr = &f;
	d = static_cast<double>(c);
	dPtr = &d;
}

static void convertInt(const std::string &str)
{
	i = std::stoi(str);
	iPtr =  &i;
	if (i >=0 && i <= 127)
	{
		c = static_cast<char>(i);
		cPtr = &c;
	}
	f = static_cast<float>(i);
	fPtr = &f;
	d = static_cast<double>(i);
	dPtr = &d;
}

static void convertFloat(const std::string &str)
{
	f = std::stof(str);
	fPtr = &f;
	d = static_cast<double>(f);
	dPtr = &d;
	if (std::trunc(f) <= static_cast<float>(std::numeric_limits<int>::max())
		&& std::trunc(f) >= static_cast<float>(std::numeric_limits<int>::min()))
	{
		i = static_cast<int>(std::trunc(f));
	}
	if (std::trunc(f) >= 0 && std::trunc(f) <= 127)
	{
		c = static_cast<char>(std::trunc(f));
		cPtr = &c;
	}
}

static void convertDouble(const std::string &str)
{
	d = std::stod(str);
	if (str == "nan")
	{
		f = std::numeric_limits<float>::quiet_NaN();
		fPtr = &f;
	}
	if (str.find("inf") != std::string::npos)
	{
		f = std::numeric_limits<float>::infinity();
		if (str.find("-") != std::string::npos)
			f = -f;
		fPtr = &f;
	}
	dPtr = &d;
	if (d <= static_cast<double>(std::numeric_limits<float>::max())
		&& d >= static_cast<double>(std::numeric_limits<float>::lowest()))
	{
		f = static_cast<float>(d);
		fPtr = &f;
	}
	if (std::trunc(d) <= static_cast<double>(std::numeric_limits<int>::max())
		&& std::trunc(d) >= static_cast<double>(std::numeric_limits<int>::min()))
	{
		i = static_cast<int>(std::trunc(d));
		iPtr = &i;
	}
	if (std::trunc(d) >= 0 && std::trunc(d) <= 127)
	{
		c = static_cast<char>(std::trunc(d));
		cPtr = &c;
	}
}


