#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <limits>

bool RPN::isOperand(char c)
{
	if (std::isdigit(c))
		return true;
	return false;
}

bool RPN::isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

// divided by 0 will throw
void RPN::applyOperator(char op)
{
	if (_stack.size() < 2)
		throw std::invalid_argument("Error");
	long long right = _stack.top();
	_stack.pop();
	long long left = _stack.top();
	_stack.pop();
	if (op == '/' && right == 0)
		throw std::invalid_argument("Error");
	switch (op) {
		case '+': _stack.push(left + right); break;
		case '-': _stack.push(left - right); break;
		case '*': _stack.push(left * right); break;
		case '/': _stack.push(left / right); break;
		default: throw std::invalid_argument("Error");
	}
	if (_stack.top() > std::numeric_limits<int>::max()
	|| _stack.top() < std::numeric_limits<int>::min())
		throw std::out_of_range("Error");
}

void RPN::process(const std::string &expr)
{
	std::istringstream iss(expr);
	std::string token;

	while (iss >> token)
	{
		if (token.size() != 1)
			throw std::invalid_argument("Error");
		if (isOperand(token[0]))
			_stack.push(token[0] - '0');
		else if (isOperator(token[0]))
			applyOperator(token[0]);
		else
			throw std::invalid_argument("Error");
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("Error");
	std::cout << _stack.top() << std::endl;
}
