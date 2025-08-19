/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:06:18 by agilles           #+#    #+#             */
/*   Updated: 2025/08/19 17:34:09 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstring>

#include <vector>
#include <list>

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
};
