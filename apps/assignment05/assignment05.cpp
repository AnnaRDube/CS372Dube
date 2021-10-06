//
// File:   assignment05.cpp
// Author: Anna Dube
// Purpose: Implement a iterative and a recursive 
// solution to the Towers of Hanoi problem
// Sources: https://www.geeksforgeeks.org/iterative-tower-of-hanoi/
// 

#include <iostream>
#include <stack>
#include <cmath>
#include<chrono>
using namespace std;

void moveDiskDisplay(int, int);
void moveDisksRec(int, int, int, int);
void moveDisksIter(int, stack<int>, stack<int>, stack<int>,
	int, int, int);
void moveBetweenPoles(stack<int>&, stack<int>&, int, int);

int main() {
	const int NUMDISKS = 50;
	const int FROMPEG = 1;
	const int TOPEG = 3;
	const int TEMPPEG = 2;

	stack<int> fromA;
	stack<int> toC;
	stack<int> tempB;

	cout << "************ Recursive ************\n";
	auto startR = std::chrono::steady_clock::now();
	moveDisksRec(NUMDISKS, FROMPEG, TOPEG, TEMPPEG);
	auto endR = std::chrono::steady_clock::now();
	cout << "All the pegs are moved! " << endl;
	std::chrono::duration<double> recursiveTime = endR - startR;
	cout << "\nElapsed time: " << recursiveTime.count() << " s \n";

	cout << "\n************ Iterative ************\n";
	auto startI = std::chrono::steady_clock::now();
	moveDisksIter(NUMDISKS, fromA, toC, tempB, FROMPEG, TOPEG, TEMPPEG);
	auto endI = std::chrono::steady_clock::now();
	cout << "All the pegs are moved!" << endl;
	std::chrono::duration<double> iterativeTime = endI - startI;
	cout << "\nElapsed time: " << iterativeTime.count() << " s \n";
	return 0;
}

void moveDiskDisplay(int fromPeg, int toPeg)
{
	cout << "Move a disk from peg " << fromPeg
		<< " to peg " << toPeg << endl;
}

void moveDisksRec(int num, int fromPeg, int toPeg, int tempPeg) {
	if (num > 0) {
		moveDisksRec(num - 1, fromPeg, tempPeg, toPeg);
		moveDiskDisplay(fromPeg, toPeg);
		moveDisksRec(num - 1, tempPeg, toPeg, fromPeg);
	}
}

void moveDisksIter(int num, stack<int> fromA, stack<int> toC, stack<int> tempB,
	int fromPegA, int toPegC, int tempPegB) {
	int total = 0;
	if (num % 2 == 0) {
		int temp = toPegC;
		toPegC = tempPegB;
		tempPegB = temp;
	}

	total = pow(2, num) - 1;

	for (int x = num; x >= 1; x--)
		fromA.push(x);
	for (int x = 1; x <= total; x++)
	{
		if (x % 3 == 1)
			moveBetweenPoles(toC, fromA, toPegC, fromPegA);
		else if (x % 3 == 2)
			moveBetweenPoles(tempB, fromA, tempPegB, fromPegA);
		else if (x % 3 == 0)
			moveBetweenPoles(tempB, toC, tempPegB, toPegC);
	}
}

void moveBetweenPoles(stack<int> &fromP, stack<int> &toP, int f, int t)
{
	int pole1Top = 0;
	int pole2Top = 0;
	if (!fromP.empty()) {
		pole1Top = fromP.top();
		fromP.pop();
	}
	if (!toP.empty())
	{
		pole2Top = toP.top();
		toP.pop();
	}
	if (pole1Top == 0)
	{
		fromP.push(pole2Top);
		moveDiskDisplay(t, f);
	}
	else if (pole2Top == 0)
	{
		toP.push(pole1Top);
		moveDiskDisplay(f, t);
	}
	else if (pole1Top > pole2Top)
	{
		fromP.push(pole1Top);
		fromP.push(pole2Top);
		moveDiskDisplay(t, f);
	}
	else
	{
		toP.push(pole2Top);
		toP.push(pole1Top);
		moveDiskDisplay(f, t);
	}
}
