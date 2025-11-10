/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcointExchange.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:28:18 by rhvidste          #+#    #+#             */
/*   Updated: 2025/11/10 15:35:15 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include <string>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange() = delete;
		BitcoinExchange(BitcoinExchange const &) = delete;
		BitcoinExchange( std::string const &inputFileName,
				  		 std::string const &dataFileName = "data.csv" );
		~BitcoinExchange() = default;

		BitcoinExchange &operator=( BitcoinExchange const & ) = delete;

		void	run();
	private:
		std::string const				_dataFileName;
		std::string const				_inputFileName;
		std::map< std::string, float >	_data;

		bool	dataParse();
		bool	inputParse();

};
