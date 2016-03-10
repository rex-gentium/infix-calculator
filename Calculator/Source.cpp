#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;

int main() {
	string inputLine;
	Calculator calculator;

	int a = -10;
	unsigned b = a;

	cout << b << endl;

	while (getline(cin, inputLine)) {
		cout << inputLine << " = ";
		float result = calculator.calculate(inputLine);
		cout << result << endl;
	}

	return 0;
}