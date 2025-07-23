/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:29:08 by agilles           #+#    #+#             */
/*   Updated: 2025/07/23 16:14:44 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "bitcoinExchange Default constructor called" << std::endl;
	this->setData();
	std::cout << std::endl;
	this->convertInput("input.txt");

	// for (std::multimap<std::string, float>::iterator it = this->_input.begin(); it != this->_input.end(); ++it)
	// {
	// 	std::cout << it->first << " | " << it->second << std::endl;
	// }
}

BitcoinExchange::BitcoinExchange(std::string input)
{
	std::cout << "bitcoinExchange Arg constructor called" << std::endl;
	this->setData();
	std::cout << std::endl;
	this->convertInput(input);

	std::cout << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cp): _data(cp._data)
{
	std::cout << "bitcoinExchange Copy constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "bitcoinExchange Deconstructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cp)
{
	std::cout << "bitcoinExchange Assignation operator called" << std::endl;
	if (this != &cp)
		return (*this);
	this->_data = cp._data;
	return (*this);
}

bool isLeapYear(int year)
{
	if (year % 4 != 0)
		return (false);
	else if (year % 100 != 0)
		return (true);
	else if (year % 400 != 0)
		return (false);
	else
		return (true);

}

bool isValidDate(const std::string& date) {
	if (date[4] != '-' || date[7] != '-')
		return false;

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (date.size() < 13)
	{
		std::cerr << "Error: Invalid input [line < 13 char] => " << date << std::endl;
		return false;
	}
	else if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cerr << "Error: Invalid date => " << date.substr(0, 10) << std::endl;
		return false;
	}
	else if (month == 2 && day == 29)
	{
		if (!isLeapYear(year))
			std::cerr << "Error: Invalid date (Leap Year) => " << date.substr(0, 10) << std::endl;
	}
	return true;
}

float	BitcoinExchange::findDate(std::string& date)
{
	for (std::map<std::string, float>::iterator it = this->_data.begin(); it != this->_data.end(); ++it)
	{
		if (it->first == date)
			return (it->second);
	}

	std::map<std::string, float>	tmp = this->_data;
	tmp[date] = 0;

	for (std::map<std::string, float>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		if (it->first == date)
		{
			it--;
			return (it->second);
		}
	}
	return (0);
}

void	BitcoinExchange::setData()
{
	std::ifstream file("data.csv");
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
			std::istringstream btc_stream(btc);
			float btc_convert;
			btc_stream >> btc_convert;

			//std::cout << date << " " << btc_convert << std::endl;
			this->_data[date] = btc_convert;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error when convert float in this line: \n" << line << std::endl;
		}
	}
	file.close();
}

void	BitcoinExchange::convertInput(std::string input)
{
	std::ifstream file(input.c_str());
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
		if (isValidDate(totrim))
		{
			date = totrim.substr(0, 10);
			btc = totrim.substr(13);
			try
			{
				std::istringstream btc_stream(btc);
				float btc_convert;
				btc_stream >> btc_convert;

				if (btc_convert < 0 || btc_convert > 1000)
					std::cerr << "Error: Input not in range 0 - 1000" << std::endl;
				else
					std::cout << date << " => " << btc_convert << " = " << findDate(date) * btc_convert << std::endl;
				// this->_input.insert(std::make_pair(date, btc_convert));
			}
			catch (const std::exception &e)
			{
				std::cerr << "Error when convert float in this line: \n" << line << std::endl;
			}
		}
	}
	file.close();
}

void	BitcoinExchange::printOutput()
{

}
