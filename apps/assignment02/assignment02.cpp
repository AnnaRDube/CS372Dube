//
// File:   assignment2.cpp
// Author: Anna Dube
// Purpose:
// To demonstrate the Bag class
// using linked lists

#include <iostream>
#include "cs372BagList.h"
using namespace std;

void bagWithReceipt();
void bagMadeWithList();

int main() {
	bagWithReceipt();
	bagMadeWithList();
	return 0;
}

void bagMadeWithList() {
	cout << "\n\n********* BagList *********\n";
		Bag<int> myBag;
		myBag.insert(30);
		myBag.insert(28);
		myBag.insert(30);
		myBag.insert(30);
		myBag.insert(21);
		myBag.insert(59);
		cout << "Bag size: " << myBag.size() << endl;
		int item = myBag.pop();
		cout << "item popped: " << item << endl;
		item = myBag.pop();
		cout << "item popped: " << item << endl;
		cout << "New Bag size: " << myBag.size() << endl;
		cout << "Amount of integer 30 in the bag: " << myBag.count(30) << endl;
		cout << "Bag size: " << myBag.size() << endl;
}
