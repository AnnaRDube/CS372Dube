//
// File:   assignment01.cpp
// Author: Anna Dube
// Purpose:
// Illustrate some of the bad things that can happen with
// pointers
//
#include <iostream>
#include <stack>
using namespace std;

void pointerAntiPattern1();
void pointerAntiPattern2();
void pointerAntiPattern3();
string stringStack();

int main()
{
	cout << "*****Problem 1*****\n";
	pointerAntiPattern1();
	cout << "\n*****Problem 2*****\n";
	pointerAntiPattern2();
	cout << "\n*****Problem 3*****\n";
	pointerAntiPattern3();
	return 0;
}

void pointerAntiPattern1() {
	int* ptr1 = nullptr;
	int* ptr2 = nullptr;
	ptr1 = new int[30];
	for (int x = 0; x < 30; x++) {
		ptr1[x] = x + 1;
	}
	ptr2 = ptr1;
	delete[] ptr1;
	ptr1 = nullptr;
	for (int x = 0; x < 10; x++) {
		cout << ptr2[x] << endl;
	}
}


void pointerAntiPattern2() {
	int* ptr1 = nullptr;
	int* ptr2 = nullptr;
	ptr1 = new int[30];
	for (int x = 0; x < 30; x++) {
		ptr1[x] = x + 1;
	}
	ptr2 = ptr1;
	delete ptr1;
	ptr1 = nullptr;

	cout << ptr2 << endl;
	for (int x = 0; x < 10; x++) {
		cout << ptr2[x] << endl;
	}
}

void pointerAntiPattern3() {
	string myString = " ";
	for (int s = 0; s < 10; s++) {
		myString = stringStack();
		cout << myString << endl;
	}
}

string stringStack() {
	static stack<string> myStack;
	static string* sptr = new string;
	*sptr = "abc";
	myStack.push(*sptr);
	return *sptr;
}
