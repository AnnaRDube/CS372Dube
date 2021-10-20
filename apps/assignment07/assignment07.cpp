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
	size_t treeSize = 0;
	vector<int> vptr;
	Tree<int> binaryTree;
};

int partition(BTree *ptr, int start, int end) {
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

void quicksort(BTree *ptr, int n) {
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
void searchTree(BTree* listOfElem, T val, bool& gotIt,
	int& last, int& first, int& mid, int& pos) {
/*	if (listOfElem->binaryTree[mid] == val)
	{
		gotIt = true;
		pos = mid;
	}
	else if (listOfElem->binaryTree[mid] > val)
		last = mid - 1;
	else
		first = mid + 1;*/
}

template <typename T>
void searchVec(BTree* listOfElem, T val, bool &gotIt, 
	int &last, int &first, int &mid, int &pos) {
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

template <typename T>
int binarySearch(BTree *listOfElem, int num, T val, bool isVec) {
	int first = 0,
		last = num - 1,
		mid,
		pos = -1;
	bool gotIt = false;
	while (!gotIt && first <= last)
	{
		mid = (first + last) / 2;
		if (isVec) {
			searchVec(listOfElem, val, gotIt, last, first, mid, pos);
		}
		else {
			searchTree(listOfElem, val, gotIt, last, first, mid, pos);
		}
	}
	return pos;
}

BTree* ptrToTree(int s) {
	unsigned int seedX = time(0);
	srand(seedX);
	int num = 0;
	int searchNum = 0;
	BTree tree1;
	tree1.treeSize = s;
	BTree* ptr = &tree1;
	int pos = 0;

	for (int x = 0; x < s; x++) {
		num = (rand() % (100 - 1 + 1)) + 1;
		tree1.vptr.push_back(num);
	}
	quicksort(ptr, s);
	for (int x = 0; x < s; x++) {
		cout << tree1.vptr[x] << " ";
	}
	cout << endl;

	//test vector
	auto start = chrono::steady_clock::now();
	for (int x = 0; x < 100; x++) {
		searchNum = (rand() % (100 - 1 + 1)) + 1;
		pos = binarySearch(ptr, s, searchNum, true);
	}
	auto end = chrono::steady_clock::now();
	chrono::duration<double> elasped_seconds_vec = end - start;

	auto f2 = [](int thing)->void {std::cout << thing; };
	for (int x = 0; x < s; x++) {
		tree1.binaryTree.insert(tree1.vptr[x]);
	}
	tree1.binaryTree.inorder(f2);
	cout << endl;

	//test binary tree
	start = chrono::steady_clock::now();
	for (int x = 0; x < 100; x++) {
		searchNum = (rand() % (100 - 1 + 1)) + 1;
		//pos = binarySearch(ptr, s, searchNum, false);
	}
	end = chrono::steady_clock::now();
	chrono::duration<double> elasped_seconds_tree = end - start;
	
	if (z == 0) {
		cout << setw(6) << "Size" << setw(15) << "Vector Time"
			<< setw(15) << "Tree Time" << endl;
		cout << "--------------------------------------------------\n";
	}
	cout << setw(5) << s << setw(15) << elasped_seconds_vec.count() 
		<< setw(15) << elasped_seconds_tree.count() << endl;

	return ptr;
}

int main() {
	BTree* Tptr;
	int size = 10;
	for (int x = 0; x < 1; x++) {
		Tptr = ptrToTree(size);
		size *= 10;
		z++;
	}
	return 0;
}
