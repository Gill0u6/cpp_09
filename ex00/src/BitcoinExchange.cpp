/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:29:08 by agilles           #+#    #+#             */
/*   Updated: 2025/07/10 17:17:32 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "bitcoinExchange Default constructor called" << std::endl;
	this->setInput("input.txt");
}

BitcoinExchange::BitcoinExchange(std::string csv, std::string input)
{
	std::cout << "bitcoinExchange Arg constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cp)
{
	(void)cp;
	std::cout << "bitcoinExchange Copy constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "bitcoinExchange Deconstructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cp)
{
	(void)cp;
	std::cout << "bitcoinExchange Assignation operator called" << std::endl;
}

void	BitcoinExchange::setData()
{
	std::ifstream file("../data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: fail to open data.csv" << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string btc;

		if (!std::getline(ss, date, ','))
			continue ;

		if (!std::getline(ss, btc))
			continue ;

		try
		{
			float	btc_convert = std::stof(btc);
			this->_data[date] = btc_convert;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error when convert float in this line: \n" << line << std::endl;
		}
	}
	file.close();
}

void	BitcoinExchange::setInput(std::string input)
{
	std::ifstream file(input);
	if (!file.is_open())
	{
		std::cerr << "Error: fail when open input file" << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string totrim;
		std::string date;
		std::string btc;

		if (!std::getline(ss, totrim, '\n'))
			continue ;
		if (totrim.size() > 13)
		{
			date = totrim.substr(0, 10);
			btc = totrim.substr(13);
			try
			{
				float	btc_convert = std::stof(btc);
				std::cout << date << " " << btc << std::endl;
				this->_data[date] = btc_convert;
			}
			catch (const std::exception &e)
			{
				std::cerr << "Error when convert float in this line: \n" << line << std::endl;
			}
		}
		else
			std::cerr << "Invalid Input" << std::endl;
	}
	file.close();
}

void	BitcoinExchange::printOutput()
{

}

