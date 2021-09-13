//
// File:   assignment03.cpp
// Author: Anna Dube
// Purpose: Test the Stack class
//
#include "cs372Container.h"
#include "cs372Stack.h"
#include <iostream>
using namespace std;

void question1() {
	Stack<int> s;
	s.push(3);
	s.push(8);
	s.push(2);
	s.push(9);
	cout <<"Stack size: " << s.size() << endl;
	cout << "Popping: " <<s.pop() << endl;
	cout << "Popping: " << s.pop() << endl;
	cout << "Popping: " << s.pop() << endl;
	cout << "Stack size: " << s.size() << endl;
	s.clear();
	cout << "Stack size: " << s.size() << endl;
}
