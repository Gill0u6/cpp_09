/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:06:25 by agilles           #+#    #+#             */
/*   Updated: 2025/07/24 17:49:45 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(): _handle_error(0)
{
	std::cout << "PmergeMe Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(std::string input): _handle_error(0)
{
		std::cout << "PmergeMe Arg constructor called" << std::endl;
		parse(input);
}

PmergeMe::PmergeMe(const PmergeMe &cp): _vec(cp._vec), _lst(cp._lst), _handle_error(0)
{
		std::cout << "PmergeMe Copy constructor called" << std::endl;
		*this = cp;
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe Deconstructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cp)
{
	std::cout << "PmergeMe Assignation operator called" << std::endl;
	if (this != &cp)
		return (*this);
	this->_vec = cp._vec;
	this->_lst = cp._lst;
	return (*this);
}

void	PmergeMe::parse(std::string input)
{
	std::string tmp;
	if (input[0] != ' ')
		{
			std::cerr << "Invalid Input:\nNot a Number here: " << input[0] << std::endl;
			return ;
		}
	for (int i = 0; input[i]; i++)
	{
		tmp = "";
		while (input[i] >= '0' && input[i] <= '9')
		{
			tmp += input[i];
			i++;
		}
		if (input[i] != ' ')
		{
			std::cerr << "Invalid Input:\nNot a WhiteSpace here: " << input[i] << std::endl;
			return ;
		}
		this->_lst.push_back(atoi(tmp.c_str()));
		this->_vec.push_back(atoi(tmp.c_str()));
		//std::cout << tmp << std::endl;
	}
}
