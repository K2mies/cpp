/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions03.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:04:00 by rhvidste          #+#    #+#             */
/*   Updated: 2025/10/15 17:14:10 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <exception>

class MyException: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Something bad happened!");
		}

};

class Test
{
	public:
		void goesWrong()
		{
			throw MyException();
		}
};

int	main()
{
	Test test;

	try 
	{
		test.goesWrong();
	}
	catch(MyException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
