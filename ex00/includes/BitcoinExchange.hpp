/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:13:06 by agilles           #+#    #+#             */
/*   Updated: 2025/07/02 18:22:14 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>

#include <sstream>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;
		std::map<std::string, float>	_input;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string csv, std::string input);
		BitcoinExchange(const BitcoinExchange &cp);

		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &cp);

		void	setData();
		void	setInput(std::string input);

		void	printOutput();
};
