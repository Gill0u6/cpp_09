/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:13:06 by agilles           #+#    #+#             */
/*   Updated: 2025/07/17 17:21:16 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>

#include <sstream>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;
		// std::multimap<std::string, float>	_input;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string input);
		BitcoinExchange(const BitcoinExchange &cp);

		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &cp);

		float	findDate(std::string& date);
		void	setData();
		void	convertInput(std::string input);

		void	printOutput();
};
