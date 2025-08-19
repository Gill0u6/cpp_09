/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:05:12 by agilles           #+#    #+#             */
/*   Updated: 2025/08/19 17:34:51 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "\nError: Wrong Argument count: " << std::endl;
		std::cerr << "You should call the progam like this: ./PmergeMe \"rdmNB rdmBN rdmNB ...\"\n" << std::endl;
		return (1);
	}
	PmergeMe t(av, ac);
	return (0);
}
