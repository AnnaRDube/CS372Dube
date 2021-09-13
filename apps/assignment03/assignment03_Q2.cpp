//
// File:   assignment03_2.cpp
// Author: Anna Dube
// Purpose: Take a fully parenthesized expression as input
// and display the expression in both prefix and postix notation.
//

#include <iostream>
#include <cctype>
#include <cstring>
#include <stack>
#include <string>
using namespace std;

void postfix(istream& ins);
void prefix(istream&);
void question1();
stack<char> tempO;

int main() {
	question1();
	string exp = "";

	cout << "\nType a fully parenthsized expression to convert to postfix" << endl;
	postfix(cin);
	cout << "Retype the expression to convert to prefix" << endl;
	cin.ignore();
	prefix(cin);
	return 0;
}

void postfix(istream& ins) {
	const char DECIMAL = '.';
	const char RIGHTPAREN = ')';
	stack<double> numbers;
	stack<char> operations;
	double number;
	char symbol;

	while (ins && ins.peek() != '\n') {
		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
			ins >> number;
			numbers.push(number);
			cout << number << " ";
		}
		else if (strchr("+-*/", ins.peek()) != NULL) {
			ins >> symbol;
			operations.push(symbol);
		}
		else if (ins.peek() == RIGHTPAREN) {
			ins.ignore();
			if (!operations.empty()) {
				cout << operations.top() << " ";
				operations.pop();
			}
		}
		else {
			ins.ignore();
		}
	}
	while (!operations.empty()) {
		tempO.push(operations.top());
		cout << operations.top() << " ";
		operations.pop();
	}
	cout << endl;
}

void prefix(istream& ins) {
	const char DECIMAL = '.';
	const char RIGHTPAREN = ')';
	stack<double> numbers;
	stack<char> operations;
	double number;
	char symbol;
	stack<double> tempN;
	int rightCount = 0;
	int leftCount = 0;


	while (ins && ins.peek() != '\n') {

		while (!tempO.empty()) {
			cout << tempO.top() << " ";
			tempO.pop();
		}
		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
			ins >> number;
			numbers.push(number);
		}
		else if (strchr("+-*/", ins.peek()) != NULL) {
			ins >> symbol;
			if (ins.peek() == '(' && !operations.empty()) {
				leftCount++;
			}
			else {
				operations.push(symbol);
			}
		}
		else if (ins.peek() == '(') {
			ins.ignore();
			if (!numbers.empty() && !operations.empty()) { leftCount++; }
		}
		else if (ins.peek() == RIGHTPAREN) {
			ins.ignore();
			rightCount++;
		}
		else {
			ins.ignore();
		}
		if (rightCount == 2 || (leftCount >= 1 && rightCount == 1)) {
			rightCount = 0;
			leftCount = 0;

			while (!operations.empty()) {
				cout << operations.top() << " ";
				operations.pop();
			}
			while (!numbers.empty()) {
				tempN.push(numbers.top());
				numbers.pop();
			}
			while (!tempN.empty()) {
				cout << tempN.top() << " ";
				tempN.pop();
			}
		}
	}
	cout << endl;
}