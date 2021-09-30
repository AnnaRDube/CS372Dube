//
// File:   assignment04.cpp
// Author: Anna Dube
// Purpose: Keep track of current tasks. Allow the 
// user to update the tasks.
// 
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void displayMenu();
struct Task {
	int taskN = 0;
	char taskC = ' ';
	string taskD = "";
};
vector<Task> myTasks;
bool changes = false;

int main() {
	int c = 0;
	ifstream file1;
	file1.open("c://Users//user//My Documents//GitHub//CS372Dube//apps//assignment04//TextFile1.txt");

	if (file1.fail()) {
		cout << "Error reading file" << endl;
	}
	else {
		Task temp;
		while (file1 >> temp.taskN >> temp.taskC) {
			getline(file1, temp.taskD);
			myTasks.push_back(temp);
		}
		do {
			displayMenu();
			cin >> c;

			if (c == 1) {
				cout << endl;
				for (int counter = 0; counter < myTasks.size(); counter++) {
					cout << myTasks[counter].taskN << " "
						<< myTasks[counter].taskC
						<< myTasks[counter].taskD << endl;
				}
				cout << endl;
			}
			else if (c == 2) {
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
							<< myTasks[x].taskD << endl << endl;
					}
				}
				if (!found) {
					cout << "Task does not exist\n\n";
				}
			}
			else if (c == 3) {
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
			else if (c == 4) {
				file1.close();

				if (changes) {
					changes = false;
					ofstream file2;
					file2.open("c://Users//user//My Documents//GitHub//CS372Dube//apps//assignment04//TextFile1.txt", ios::trunc);
					if (file2.fail()) {
						cout << "Error reading file" << endl;
					}
					else {
						for (int x = 0; x < myTasks.size(); x++) {
							if (myTasks[x].taskC == 'U') {
								file2 << myTasks[x].taskN << " "
									<< myTasks[x].taskC
									<< myTasks[x].taskD << endl;
							}
						}
					}
					file2.close();
				}
			}
			else {
				cout << "\n*** Invalid. Enter a number 1-4. ***\n\n";
			}
		} while (c != 4);
	}
	return 0;
}

void displayMenu() {
	cout << "1. Display all items\n"
		<< "2. Display selected item\n"
		<< "3. Mark a task as done\n"
		<< "4. Exit the program\n"
		<< "Enter your choice (1-4): ";
}
