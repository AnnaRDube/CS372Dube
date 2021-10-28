//
// File:   assignment08_2.cpp
// Author: Anna Dube
// Purpose:
// Sort data based on the priority attribute
// using the STL priority_queue
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void displayMenu();
void menuChoice1();
void menuChoice2();
void menuChoice3();
void menuChoice4();
void menuChoice5();

struct Task {
	int taskN = 0;
	char taskC = ' ';
	string taskD = "";
	int taskP = 0;

	bool operator<(const Task& rhs) const
	{
		return taskP < rhs.taskP;
	}
};
vector<Task> myTasks;
priority_queue<Task> pq;
bool changes = false;
ifstream file1;

int main() {
	int c = 0;

	file1.open("TextFile.txt");
	if (file1.fail()) {
		cout << "Error reading file" << endl;
	}
	else {
		Task temp;
		string hold = "";

		while (!file1.eof()) {
			file1 >> temp.taskN >> temp.taskC;
			getline(file1, hold);
			if (file1.end) {
				temp.taskD = "", temp.taskP = 0;
				
				for (int x = 0; x < hold.size(); x++) {
					if (isalpha(hold[x]) || hold[x] == ' ') {
						temp.taskD += hold[x];
					}
					if (isdigit(hold[x]) && x == hold.size() - 1) {
						temp.taskP = ((int)hold[x]) - 48;
					}
					else if (isdigit(hold[x]) && x < hold.size() - 1) {
						// number has two digits
						temp.taskP = ((((int)hold[x]) - 48) * 10) + (((int)hold[x + 1]) - 48);	
						break;
					}
				}
				pq.push(temp);
			}
		}

		while (!pq.empty()) {
			Task t1 = pq.top();
			myTasks.push_back(t1);
			pq.pop();
		}

		do {
			displayMenu();
			cin >> c;

			if (c == 1) {
				menuChoice1();
			}
			else if (c == 2) {
				menuChoice2();
			}
			else if (c == 3) {
				menuChoice3();
			}
			else if (c == 4) {
				menuChoice4();
			}
			else if (c == 5) {
				menuChoice5();
			}
			else {
				cout << "\n*** Invalid. Enter a number 1-5. ***\n\n";
			}
		} while (c != 5);
	}
	return 0;
}

void menuChoice1() {
	cout << endl;
	for (int counter = 0; counter < myTasks.size(); counter++) {
		cout << myTasks[counter].taskN << " "
			<< myTasks[counter].taskC
			<< myTasks[counter].taskD 
			<< myTasks[counter].taskP << endl;
	}
	cout << endl;
}

void menuChoice2() {
	int num;
	bool found = false;
	cout << "\nEnter a task number: ";
	cin >> num;
	cout << endl;

	for (int x = 0; x < myTasks.size(); x++) {
		if (myTasks[x].taskN == num) {
			found = true;
			cout << myTasks[x].taskN << " "
				<< myTasks[x].taskC
				<< myTasks[x].taskD 
				<< myTasks[x].taskP << endl << endl;
		}
	}
	if (!found) {
		cout << "Task does not exist\n\n";
	}
}

void menuChoice3() {
	int num;
	bool found = false;
	cout << "\nEnter the task number to mark as done: ";
	cin >> num;
	cout << endl;
	for (int x = 0; x < myTasks.size(); x++) {
		if (myTasks[x].taskN == num) {
			found = true;
			myTasks[x].taskC = 'D';
			changes = true;
		}
	}
	if (!found) {
		cout << "Task does not exist\n\n";
	}
}

void menuChoice4() {
	int num, p;
	bool found = false;
	cout << "\nEnter the task number to change priority: ";
	cin >> num;
	cout << "Enter the new priority: ";
	cin >> p;
	cout << endl;
	for (int x = 0; x < myTasks.size(); x++) {
		if (myTasks[x].taskN == num) {
			found = true;
			myTasks[x].taskP = p;
			changes = true;
		}
	}
	if (!found) {
		cout << "Task does not exist\n\n";
	}
	else {
		int s = myTasks.size();
		for (int x = 0; x < s; x++) {
			pq.push(myTasks.back());
			myTasks.pop_back();
		}
		while (!pq.empty()) {
			Task t1 = pq.top();
			myTasks.push_back(t1);
			pq.pop();
		}
	}
}

void menuChoice5() {
	file1.close();

	if (changes) {
		changes = false;
		ofstream file2;
		file2.open("TextFile.txt", ios::trunc);
		if (file2.fail()) {
			cout << "Error reading file" << endl;
		}
		else {
			for (int x = 0; x < myTasks.size(); x++) {
				if (myTasks[x].taskC == 'U') {
					file2 << myTasks[x].taskN << " "
						<< myTasks[x].taskC
						<< myTasks[x].taskD
						<< myTasks[x].taskP << endl;
				}
			}
		}
		file2.close();
	}
}

void displayMenu() {
	cout << "1. Display all items\n"
		<< "2. Display selected item\n"
		<< "3. Mark a task as done\n"
		<< "4. Change Priority\n"
		<< "5. Exit the program\n"
		<< "Enter your choice (1-5): ";
}
