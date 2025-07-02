/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:13:06 by agilles           #+#    #+#             */
/*   Updated: 2025/07/02 17:45:49 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>

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

		void	setData(std::string csv, std::string input);
		void	printOutput();
};
