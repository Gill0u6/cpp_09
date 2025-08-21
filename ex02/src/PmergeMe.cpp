/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:06:25 by agilles           #+#    #+#             */
/*   Updated: 2025/08/21 16:27:14 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(): _handle_error(0)
{

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

		clock_t start = clock();
		_vec = mergeSortVector(_vec);
		clock_t end = clock();
		std::cout << "After:\t";
		for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		double duration = (double)(end - start) / CLOCKS_PER_SEC;
		std::cout	<< "Time to process a range of " << _vec.size()
					<< " elements with std::vector : "
					<< std::fixed << std::setprecision(6) << duration << " us" << std::endl;

		start = clock();
		_lst = mergeSortList(_lst);
		end = clock();

		duration = (double)(end - start) / CLOCKS_PER_SEC;
		std::cout	<< "Time to process a range of " << _lst.size()
					<< " elements with std::list : "
					<< std::fixed << std::setprecision(6) << duration << " us" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &cp): _vec(cp._vec), _lst(cp._lst), _handle_error(0)
{
		*this = cp;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cp)
{
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
		if ((input[j][0] < '0' || input[j][0] > '9'))
		{
			std::cerr << "Invalid Input:\nNot a Number here: " << input[0] << std::endl;
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
				std::cerr << "Invalid Input:\nNot a Number here: " << input[j][i] << std::endl;
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
/*====Slow Version But Working Version====*/
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

/*=========================================*/
		//			VECTOR			//

std::vector<int> PmergeMe::mergeVector(const std::vector<int>& left, const std::vector<int>& right)
{
	std::vector<int> result;
	result.reserve(left.size() + right.size());

	size_t l = 0, r = 0;
	while (l < left.size() && r < right.size())
	{
		if (left[l] <= right[r])
			result.push_back(left[l++]);
		else
			result.push_back(right[r++]);
	}

	while (l < left.size()) result.push_back(left[l++]);
	while (r < right.size()) result.push_back(right[r++]);

	return result;
}

std::vector<int> PmergeMe::mergeSortVector(const std::vector<int>& cont)
{
	if (cont.size() <= 1)
		return cont;

	size_t mid = cont.size() / 2;
	std::vector<int> left(cont.begin(), cont.begin() + mid);
	std::vector<int> right(cont.begin() + mid, cont.end());

	left = mergeSortVector(left);
	right = mergeSortVector(right);

	return mergeVector(left, right);
}

/*=========================================*/
		//			LIST			//

std::list<int> PmergeMe::mergeList(std::list<int>& left, std::list<int>& right)
{
	std::list<int> result;

	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			result.push_back(left.front());
			left.pop_front();
		}
		else
		{
			result.push_back(right.front());
			right.pop_front();
		}
	}

	if (!left.empty())
		result.splice(result.end(), left);
	if (!right.empty())
		result.splice(result.end(), right);

	return (result);
}

std::list<int> PmergeMe::mergeSortList(std::list<int>& cont)
{
	if (cont.size() <= 1)
		return cont;

	std::list<int> right;
	std::list<int> left;

	std::list<int>::iterator midIt = cont.begin();
	std::advance(midIt, cont.size() / 2);

	left.splice(left.begin(), cont, cont.begin(), midIt);
	right.splice(right.begin(), cont, cont.begin(), cont.end());

	left = mergeSortList(left);
	right = mergeSortList(right);

	return (mergeList(left, right));
}


