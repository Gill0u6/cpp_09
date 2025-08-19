/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:06:25 by agilles           #+#    #+#             */
/*   Updated: 2025/08/19 17:34:42 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(): _handle_error(0)
{
	std::cout << "PmergeMe Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(char** input, int ac): _handle_error(0)
{
		std::cout << "PmergeMe Arg constructor called" << std::endl;
		parse(input, ac);
		if (this->_handle_error == 1)
			return ;

		std::cout << "Before:\t";
		for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		_vec = mergeSort(_vec);
		_lst = mergeSort(_lst);

		std::cout << "After:\t";
		for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;


		// for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
		// std::cout << "   _vec: " << *it << std::endl;

		// for (std::list<int>::iterator it = _lst.begin(); it != _lst.end(); it++)
		// std::cout << "\t_lst: " << *it << std::endl;
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
	this->_lst.push_back(static_cast<int>(result));
	this->_vec.push_back(static_cast<int>(result));
	return true;
}

void	PmergeMe::parse(char** input, int ac)
{
	std::string tmp;
	for (int j = 1; j < ac; j++)
	{
		if ((input[j][0] < '0' || input[j][0] > '9') && input[j][0] != '-')
		{
			std::cerr << "Invalid Input:\n1Not a Number here: " << input[0] << std::endl;
			return ;
		}
		for (size_t i = 0; i < strlen(input[j]); i++)
		{
			tmp = "";
			while (input[j][i] >= '0' && input[j][i] <= '9')
			{
				tmp += input[j][i];
				i++;
			}
			if (input[j][i] != '\0')
			{
				std::cerr << "Invalid Input:\n2Not a Number here: " << input[j][i] << std::endl;
				this->_handle_error = 1;
				return ;
			}
			if (!safe_atoi(tmp))
			{
				this->_handle_error = 1;
				std::cout << "Invalid Input: all number need to be in range [INT_MAX, INT_MIN]" << std::endl;
				return ;
			}
		}
	}
}

 template<typename Container>
Container	PmergeMe::mergeSort(const Container& cont)
{
	if (cont.size() <= 1)
		return cont;

	typename Container::const_iterator midIt = cont.begin();
	std::advance(midIt, cont.size() / 2);
	Container	left(cont.begin(), midIt);
	Container	right(midIt, cont.end());

	for (typename Container::iterator it = left.begin(); it != left.end(); it++)
	for (typename Container::iterator it = right.begin(); it != right.end(); it++)

	left = mergeSort(left);
	right = mergeSort(right);

	return (sort(left, right));
}
 template <typename Container>
Container	PmergeMe::sort(const Container& left, const Container& right)
{
	Container result;
	typename Container::const_iterator l = left.begin();
	typename Container::const_iterator r = right.begin();

	while (l != left.end() && r != right.end())
	{
		if (*l < *r)
			result.push_back(*l++);
		else
			result.push_back(*r++);
	}
	while (l != left.end())  result.push_back(*l++);
	while (r != right.end()) result.push_back(*r++);
	return(result);
}

