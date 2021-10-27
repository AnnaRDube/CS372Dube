//
// File:   assignment08.cpp
// Author: Anna Dube
// Purpose:
// 
//
#include <iostream>
#include <list>
#include <iterator>
#include "Tree.h"
using namespace std;

list<int> ascendTree(Tree<int>);
list<int> descendTree(Tree<int>);

void displayContents(list<int> result) {
	list<int>::iterator it = result.begin();
	for (it; it != result.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

list<int> treeItemList;
void f3(int thing) {
	treeItemList.push_back(thing);
}

int main() {
	Tree <int> tree1 = { 47, 74, 28, 32, 45, 43, 100 };
	list<int> result = ascendTree(tree1);
	displayContents(result);
	result = descendTree(tree1);
	displayContents(result);

	return 0;
}

list<int> ascendTree(Tree<int> tree1) {
	cout << "Ascending:\n";
	list<int> AtreeList;
	tree1.inorder(f3);
	list<int>::iterator it = treeItemList.begin();
	for (it; it != treeItemList.end(); ++it) {
		AtreeList.push_back(*it);
	}
	return AtreeList;
}

list<int> descendTree(Tree<int> tree1) {
	cout << "Descending:\n";
	list<int> DtreeList;
	int s = treeItemList.size();
	for (int x = 0; x < s; x++) {
		DtreeList.push_back(treeItemList.back());
		treeItemList.pop_back();
	}
	return DtreeList;
}