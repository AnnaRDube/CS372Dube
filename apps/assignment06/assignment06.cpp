//
// File:   assignment06.cpp
// Author: Anna Dube
// Purpose: Implement and test the anyEqual 
// algorithm.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <cmath>
using namespace std;

const int sizeX = 20;
int anyEqual(int, int**);

int main() {
	int** ptr = nullptr;
	unsigned s = time(0);
	srand(s);
	int randNum = 0;
	int equalX = 0;

	cout << setw(13) << "Array Size" << setw(15) << "Time" 
		<< setw(21) << "Average complexity" << endl;
	cout << "----------------------------------------------------\n";

	for (auto arrSize : { 10, 20, 30, 40, 50, 100, 500, 1000 }) {
		equalX = 0;
		ptr = new int* [arrSize];

		for (int i = 0; i < arrSize; i++)
			ptr[i] = new int[sizeX];

		for (int x = 0; x < arrSize; x++) {
			for (int y = 0; y < sizeX; y++) {
				randNum = (rand() % (100 - 1 + 1)) + 1;
				ptr[x][y] = randNum;
			}
		}
		
		auto start = chrono::steady_clock::now();
		equalX = anyEqual(arrSize, ptr);
		auto end = chrono::steady_clock::now();
		chrono::duration<double> elasped_seconds = end - start;
		cout << setw(4) << arrSize << "*20=" << setw(5) 
			<< arrSize*sizeX << setw(14) << elasped_seconds.count() << "s" 
			<< setw(21) << pow(arrSize, 2) * pow(sizeX, 2) << endl;
	}
	delete[] ptr;
	return 0;
}

int anyEqual(int n, int** A)
{
	int i, j, k, m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < sizeX; j++) {
			for (k = 0; k < n; k++) {
				for (m = 0; m < sizeX; m++) {
					if (A[i][j] == A[k][m] && !(i == k && j == m)) {
						return 1;
					}
				}
			}
		}
	}
	return 0;
}