/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:29:08 by agilles           #+#    #+#             */
/*   Updated: 2025/07/02 17:47:36 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "bitcoinExchange Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string csv, std::string input)
{
	std::cout << "bitcoinExchange Arg constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cp)
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
}

void	BitcoinExchange::setData(std::string csv, std::string input)
{
	
}

void	BitcoinExchange::printOutput()
{

}

