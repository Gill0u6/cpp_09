/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:06:25 by agilles           #+#    #+#             */
/*   Updated: 2025/07/31 18:18:29 by agilles          ###   ########.fr       */
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
		if (this->_handle_error == 1)
			return ;
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

bool	PmergeMe::safe_atoi(std::string nb)
{
	char *end;
	long result = std::strtol(nb.c_str(), &end, 10);

	if (result > INT_MAX || result < INT_MIN || *end != '\0')
		return false;
	//std::cout << "res: " << static_cast<int>(result) << std::endl;
	this->_lst.push_back(static_cast<int>(result));
	this->_vec.push_back(static_cast<int>(result));
	return true;
}

void	PmergeMe::parse(std::string input)
{
	std::string tmp;
	if (input[0] < '0' && input[0] > '9')
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
		if (input[i] != ' ' && input[i] != '\0')
		{
			std::cerr << "Invalid Input:\nNot a WhiteSpace here: " << input[i] << std::endl;
			this->_handle_error = 1;
			return ;
		}
		if (!safe_atoi(tmp))
		{
			this->_handle_error = 1;
			std::cout << "Invalid Input: all number need to be in range [INT_MAX, INT_MIN]" << std::endl;
			return ;
		}
		//std::cout << tmp << std::endl;
	}
	for (std::list<int>::iterator it = this->_lst.begin(); it != this->_lst.end(); it++)
		std::cout << "lst: " << *it << std::endl;
}

void	PmergeMe::mergeSort(std::vector<int> array)
{
	long len = array.size();
	if (len <= 1)
		return ;
	std::vector<int>	left;
	std::vector<int>	right;
}
