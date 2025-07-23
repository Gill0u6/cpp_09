/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:08:18 by agilles           #+#    #+#             */
/*   Updated: 2025/07/23 17:10:26 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>

class Rpn
{
	private:
		std::stack<int>		_stack;
		//std::stack<char>	_operator;
		int					_handle_error;
		int					_nb;

		void	add();
		void	remove();
		void	mult();
		void	div();

	public:
		Rpn();
		Rpn(std::string input);
		Rpn(const Rpn &cp);

		~Rpn();

		Rpn		&operator=(const Rpn &cp);

		void	readInput(std::string input);
		void	operate(char c);
};
