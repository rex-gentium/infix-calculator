#pragma once
#include <string>
#include <stack>

using namespace std;

class Calculator {
private:
	stack<float> _operands;
	stack<char> _operators;

public:
	Calculator();
	~Calculator();

	float calculate(string infix);

	const static char signAddition			= '+';
	const static char signSubtraction		= '-';
	const static char signMultiplication	= '*';
	const static char signDivision			= '/';
	const static char signExponentiation	= '^';

	float calculate(float operand1, float operand2, char oper);

private:
	unsigned getPriority(char oper); // returns priority of operation
	void performOperation(char oper);	// pops up 2 operands from stack, pushes result of oper in stack

	bool isDigit(char c);
	bool isFloatingPoint(char c);
	bool isOpenParenthesis(char c);
	bool isCloseParenthesis(char c);
	bool isDelimitter(char c);
	bool isOperator(char c);
};

