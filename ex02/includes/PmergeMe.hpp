/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:06:18 by agilles           #+#    #+#             */
/*   Updated: 2025/08/21 16:15:17 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstring>

#include <vector>
#include <list>

#include <ctime>
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::list<int>		_lst;

		int					_handle_error;

	public:
		PmergeMe();
		PmergeMe(char** input, int ac);
		PmergeMe(const PmergeMe &cp);

		~PmergeMe();

		PmergeMe		&operator=(const PmergeMe &cp);

		bool	safe_atoi(std::string nb);
		void	parse(char** input, int ac);

		 template<typename Container>
		Container	mergeSort(const Container& cont);
		 template <typename Container>
		Container	sort(const Container& left, const Container& right);

		std::list<int> mergeList(std::list<int>& left, std::list<int>& right);
		std::list<int> mergeSortList(std::list<int>& cont);

		std::vector<int> mergeVector(const std::vector<int>& left, const std::vector<int>& right);
		std::vector<int> mergeSortVector(const std::vector<int>& cont);

};
