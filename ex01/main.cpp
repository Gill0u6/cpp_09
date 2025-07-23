/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:03:39 by agilles           #+#    #+#             */
/*   Updated: 2025/07/23 17:26:30 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Rpn.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cerr << "\nError: Wrong Argument count: " << std::endl;
		std::cerr << "You should call the progam like this: ./rpn \"1 2 + 4 5 + +\"\n" << std::endl;

		std::cout << "--------------------------" << std::endl;

		std::cout << "I'm starting the program with for subject test so you don't have to:" << std::endl;
		std::cout << "./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		Rpn test1("8 9 * 9 - 9 - 9 - 4 - 1 +");

		std::cout << "--------------------------" << std::endl;

		std::cout << "./RPN \"7 7 * 7 -\"" << std::endl;
		Rpn test2("7 7 * 7 -");

		std::cout << "--------------------------" << std::endl;

		std::cout << "./RPN \"1 2 * 2 / 2 * 2 4 - +\"" << std::endl;
		Rpn test3("1 2 * 2 / 2 * 2 4 - +");

		std::cout << "--------------------------" << std::endl;

		std::cout << "./RPN \"(1 + 1)\"" << std::endl;
		Rpn test4("(1 + 1)");

		return (1);
	}
	Rpn rpn(av[1]);
	return (0);
}
