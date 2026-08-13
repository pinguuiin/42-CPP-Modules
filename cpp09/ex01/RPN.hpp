#pragma once

#include <string>
#include <stack>

class RPN {

	public:
		RPN() = default;
		RPN(const RPN &o) = default;
		RPN &operator=(const RPN &o) = default;
		~RPN() = default;

		void process(const std::string &expr);
		bool isOperand(char c);  // single digit 0-9
		bool isOperator(char c);  //+ - / *
		void applyOperator(char op);

	private:
		std::stack<long long> _stack;
};
