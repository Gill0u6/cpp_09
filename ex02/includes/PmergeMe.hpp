/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:06:18 by agilles           #+#    #+#             */
/*   Updated: 2025/07/24 17:37:01 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
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
		PmergeMe(std::string input);
		PmergeMe(const PmergeMe &cp);

		~PmergeMe();

		PmergeMe		&operator=(const PmergeMe &cp);

		void	parse(std::string input);
};
