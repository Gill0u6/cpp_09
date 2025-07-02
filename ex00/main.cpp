/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:48:10 by agilles           #+#    #+#             */
/*   Updated: 2025/07/02 17:50:07 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Wrong Argument count: " << std::endl;
		std::cerr << "\t You should call the progam like this: ./btc input.txt" << std::endl;
		return (1);
	}
	return (0);
}
