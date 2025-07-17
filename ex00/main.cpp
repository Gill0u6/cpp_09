/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:48:10 by agilles           #+#    #+#             */
/*   Updated: 2025/07/17 15:56:09 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cerr << "Error: Wrong Argument count: " << std::endl;
		std::cerr << "\t You should call the progam like this: ./btc input.txt" << std::endl;
		return (1);
	}
	BitcoinExchange btc(av[1]);
	return (0);
}
