//
// File:   assignment7.cpp
// Author: Anna Dube
// Purpose:
// To implement and test the Tree class
//
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <iomanip>
#include <chrono>
#include "Tree.h"
using namespace std;

int z = 0;

struct BTree {
	size_t treeSize = 1;
	vector<int> vptr;
	Tree<int> binaryTree;
};

int partition(BTree* ptr, int start, int end) {
	int pivot = ptr->vptr[end];
	int pIndex = start;
	for (int i = start; i < end; i++) {
		if (ptr->vptr[i] <= pivot) {
			swap(ptr->vptr[i], ptr->vptr[pIndex]);
			pIndex++;
		}
	}
	swap(ptr->vptr[pIndex], ptr->vptr[end]);
	return pIndex;
}

void quicksort(BTree* ptr, int n) {
	stack<pair<int, int>> s;
	int start = 0;
	int end = n - 1;
	s.push(make_pair(start, end));
	while (!s.empty()) {
		start = s.top().first, end = s.top().second;
		s.pop();
		int pivot = partition(ptr, start, end);
		if (pivot - 1 > start) {
			s.push(make_pair(start, pivot - 1));
		}
		if (pivot + 1 < end) {
			s.push(make_pair(pivot + 1, end));
		}
	}
}

template <typename T>
int binarySearch(BTree* listOfElem, int num, T val) {
	int first = 0,
		last = num - 1,
		mid,
		pos = -1;
	bool gotIt = false;
	while (!gotIt && first <= last)
	{
		mid = (first + last) / 2;
		if (listOfElem->vptr[mid] == val)
		{
			gotIt = true;
			pos = mid;
		}
		else if (listOfElem->vptr[mid] > val)
			last = mid - 1;
		else
			first = mid + 1;
	}
	return pos;
}

BTree* ptrToTree(int s) {
	int num = 0;
	int searchNum = 0;
	BTree tree1;
	tree1.treeSize = s;
	BTree* ptr = &tree1;
	int pos = 0;
	bool inTree = false;
	chrono::duration<double> elasped_seconds_vec, 
		elasped_seconds_tree;


	srand(time(0));
	//initialize vector
	for (int x = 0; x < s; x++) {
		num = (rand() % (10000 - 1 + 1)) + 1;
		tree1.vptr.push_back(num);
	}
	quicksort(ptr, s);

	// initialize tree
	for (int r = 0; r < s; r++) {
		tree1.binaryTree = tree1.binaryTree.insert(tree1.vptr[r]);
	}

	//test vector and tree
	for (int x = 0; x < 100; x++) {
		searchNum = (rand() % (10000 - 1 + 1)) + 1;

		auto start = chrono::steady_clock::now();
		pos = binarySearch(ptr, s, searchNum);
		auto end = chrono::steady_clock::now();
		if (x == 0) { elasped_seconds_vec = end - start; }
		else { elasped_seconds_vec += (end - start); }

		start = chrono::steady_clock::now();
		inTree = tree1.binaryTree.member(searchNum);
		end = chrono::steady_clock::now();
		if (x == 0) { elasped_seconds_tree = end - start; }
		else { elasped_seconds_tree += (end - start); }
	}
	
	if (z == 0) {
		cout << setw(6) << "Size" << setw(20) << "Vector Time"
			<< setw(20) << "Tree Time" << endl;
		cout << "--------------------------------------------------\n";
	}
	cout << setw(5) << s << setw(20) << (elasped_seconds_vec.count() / 100) << "s"
		<< setw(20) << (elasped_seconds_tree.count() / 100) << "s" << endl;

	return ptr;
}

int main() {
	BTree* Tptr;
	int size = 1000;
	for (int x = 0; x < 3; x++) {
		Tptr = ptrToTree(size);
		size *= 10;
		z++;
	}
	return 0;
}
