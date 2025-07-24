/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:08:33 by agilles           #+#    #+#             */
/*   Updated: 2025/07/24 16:44:29 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Rpn.hpp"

Rpn::Rpn(): _handle_error(0), _nb(0)
{
	std::cout << "RPN Default constructor called" << std::endl;
}

Rpn::Rpn(std::string input): _handle_error(0), _nb(0)
{
		std::cout << "RPN Arg constructor called" << std::endl;
		readInput(input);
		if (this->_handle_error == 0)
			std::cout << this->_stack.top() << std::endl;
}

Rpn::Rpn(const Rpn &cp)
{
		std::cout << "RPN Copy constructor called" << std::endl;
		*this = cp;
}

Rpn::~Rpn()
{
	std::cout << "RPN Deconstructor called" << std::endl;
}

Rpn &Rpn::operator=(const Rpn &cp)
{
	std::cout << "RPN Assignation operator called" << std::endl;
	if (this != &cp)
		return (*this);
	this->_stack = cp._stack;
	// this->_operator = cp._operator;
	return (*this);
}

void	Rpn::readInput(std::string input)
{
	std::string	tmp;
	tmp = "";
	for (int i = 0; input[i] && this->_handle_error != 1; i++)
	{
		if (i % 2 == 0 && input[i] >= '0' && input[i] <= '9')
		{
			this->_stack.push(input[i] - '0');
			this->_nb++;
		}
		else if (i % 2 == 0 && (input[i] == '+' || input[i] == '-' ||
			input[i] == '*' || input[i] == '/'))
		{
			if (_nb < 2)
			{
				std::cerr << "Invalid Input:\nYou put to many operator in front, this one cause problem: " << input[i] << std::endl;
				this->_handle_error = 1;
				return ;
			}
			//this->_operator.push(input[i]);
			operate(input[i]);
		}
		else if (i % 2 == 0)
		{
			std::cerr << "Invalid Input:\nNot a Number here: " << input[i] << std::endl;
			this->_handle_error = 1;
			return ;
		}
		else if (input[i] != ' ')
		{
			std::cerr << "Invalid Input:\nNot a WhiteSpace here: " << input[i] << std::endl;
			this->_handle_error = 1;
			return ;
		}
	}
}

void	Rpn::add()
{
	int	a = this->_stack.top();
	this->_stack.pop();
	int	b = this->_stack.top();
	this->_stack.pop();

	this->_nb--;
	this->_stack.push(b + a);
}

void	Rpn::remove()
{
	int	a = this->_stack.top();
	this->_stack.pop();
	int	b = this->_stack.top();
	this->_stack.pop();

	this->_nb--;
	this->_stack.push(b - a);
}

void	Rpn::mult()
{
	int	a = this->_stack.top();
	this->_stack.pop();
	int	b = this->_stack.top();
	this->_stack.pop();

	this->_nb--;
	this->_stack.push(b * a);
}

void	Rpn::div()
{
	int	a = this->_stack.top();
	this->_stack.pop();
	int	b = this->_stack.top();
	this->_stack.pop();

	this->_nb--;
	if (a == 0)
	{
		std::cerr << "Error: Cannot div by 0" << std::endl;
		this->_handle_error = 1;
		return ;
	}
	this->_stack.push(b / a);
}

void	Rpn::operate(char c)
{
	void		(Rpn::*ptr_func[4])(void) = {&Rpn::add, &Rpn::remove, &Rpn::mult, &Rpn::div};
	std::string	input = "+-*/";

	for (int i = 0; i < 4; i++)
	{
		if (input[i] == c)
		{
			(this->*ptr_func[i])();
			break;
		}
	}
}
