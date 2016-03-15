#include "Calculator.h"

Calculator::Calculator() {}

Calculator::~Calculator() {}

float Calculator::calculate(string infix) {

	for (int i = 0; i < infix.length(); i++) {

		char c = infix[i];
		
		if (isDelimitter(c))
			continue;

		if (isDigit(c) || isFloatingPoint(c)) {
			size_t k = 0;
			_operands.push(stof(infix.substr(i), &k));
			i += k - 1;
		}

		else if (isOpenParenthesis(c))
			_operators.push(c);
		
		else if (isCloseParenthesis(c)) {
			while (!isOpenParenthesis(_operators.top())) {
				performOperation(_operators.top());
				_operators.pop();
			}
			_operators.pop();
		}
		else if (isOperator(c)) {
			while (!_operators.empty() && getPriority(c) <= getPriority(_operators.top())) {
				performOperation(_operators.top());
				_operators.pop();
			}
			_operators.push(c);
		}
	}

	if (readingNumber)
		_operands.push(stof(number, nullptr));

	while (!_operators.empty()) {
		performOperation(_operators.top());
		_operators.pop();
	}

	return _operands.top();
}

bool Calculator::isDigit(char c) {
	return (c >= '0' && c <= '9');
}

bool Calculator::isFloatingPoint(char c) {
	return (c == '.' || c == ',');
}

bool Calculator::isOpenParenthesis(char c) {
	return (c == '(');
}

bool Calculator::isCloseParenthesis(char c) {
	return (c == ')');
}

bool Calculator::isDelimitter(char c) {
	return (c == ' ');
}

bool Calculator::isOperator(char c) {
	return (c == signAddition || 
		c == signSubtraction || 
		c == signMultiplication || 
		c == signDivision || 
		c == signExponentiation
		);
}

float Calculator::calculate(float operand1, float operand2, char oper) {
	switch (oper) {
	case signAddition: 
		return (operand1 + operand2);
	case signSubtraction:
		return (operand1 - operand2);
	case signMultiplication:
		return (operand1 *  operand2);
	case signDivision:
		return (operand1 / operand2);
	case signExponentiation:
		return (pow(operand1, operand2));
	default:
		return 0.0f;
	}
}

unsigned Calculator::getPriority(char oper) {
	switch (oper) {
	case signAddition:
	case signSubtraction:
		return 1;
	case signMultiplication:
	case signDivision:
		return 2;
	case signExponentiation:
		return 3;
	default:
		return 0;
	}
}

void Calculator::performOperation(char oper) {
	float operand2 = _operands.top();
	_operands.pop();
	float operand1 = _operands.top();
	_operands.pop();
	_operands.push(calculate(operand1, operand2, oper));
}
