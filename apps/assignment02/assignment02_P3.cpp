//
// File:   assignment2_P3.cpp
// Author: Anna Dubé
// Purpose:
// To demonstrate the ReceiptBag class
// using vectors

#include <iostream>
#include "cs372ReceiptBag.h"
using namespace std;

void bagWithReceipt() {
	ReceiptBag<char>* bag1 = new ReceiptBag<char>;
	char ans = ' ';
	int item = 0;

	cout << "********* ReceiptBag *********\n";
	cout << "Receipt: " << bag1->insert('A') << "; Item: " << 'A' << endl;
	cout << "Receipt: " << bag1->insert('G') << "; Item: " << 'G' << endl;
	cout << "Receipt: " << bag1->insert('T') << "; Item: " << 'T' << endl;
	cout << "Receipt: " << bag1->insert('R') << "; Item: " << 'R' << endl;
	cout << "Receipt: " << bag1->insert('H') << "; Item: " << 'H' << endl;
	cout << "Receipt: " << bag1->insert('L') << "; Item: " << 'L' << endl;
	cout << "Receipt: " << bag1->insert('Q') << "; Item: " << 'Q' << endl;
	cout << "Receipt: " << bag1->insert('T') << "; Item: " << 'T' << endl;
	cout << "Receipt: " << bag1->insert('E') << "; Item: " << 'E' << endl;
	cout << "Receipt: " << bag1->insert('Y') << "; Item: " << 'Y' << endl;
	cout << "Receipt: " << bag1->insert('T') << "; Item: " << 'T' << endl;
	cout << "counting Ts....  " << bag1->count('T') << endl;
	cout << "Current bag size: " << bag1->size() << endl;
	
	while (1 == 1) {
		cout << "Do you want to remove an item?(Y/N)" << endl;
		cin >> ans;
		if (ans == 'Y' || ans == 'y') {
			cout << "Enter the receipt number: " << endl;
			cin >> item;
			cout << "Item removed: " << bag1->pop(item) << endl;
			cout << "New bag size: " << bag1->size() << endl;
			break;
		}
		else if (ans == 'N' || ans == 'n') {
			break;
		}
	}
	delete bag1;
	bag1 = nullptr;
}
