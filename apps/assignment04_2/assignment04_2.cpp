//
// File:   assignment04Q2.cpp
// Author: Anna Dube
// Purpose: Find every use of a word in a file and print a sorted list
// showing each of those uses with three words before and three words after. 
// Sources:
//https://stackoverflow.com/questions/19138983/c-remove-punctuation-from-string
//https://stackoverflow.com/questions/23418390/how-to-convert-a-c-string-to-uppercase

#include <iostream>
#include <list>
#include <fstream>
#include <map>
#include <queue>
#include <cctype>
using namespace std;


void mapDictionary();
list <string> words;
list<string>::iterator position;

int main()
{
	fstream wordFile;
	string name;
	wordFile.open("c://Users//user//My Documents//GitHub//CS372Dube//apps//assignment04_2//Document1.txt");

	if (wordFile.fail()) {
		cout << "Error\n";
	}
	else {
		while (!wordFile.eof()) {
			string wordsInFile;
			wordFile >> wordsInFile;
			transform(wordsInFile.begin(), wordsInFile.end(),
				wordsInFile.begin(), ::toupper);
			wordsInFile.erase(remove_if(wordsInFile.begin(),
				wordsInFile.end(), ispunct), wordsInFile.end());
			words.push_back(wordsInFile);
		}
		for (int x = 0; x < 3; x++) {
			words.push_back(" ");
			words.push_front(" ");
		}
		wordFile.close();
		mapDictionary();
		return 0;
	}
}

void mapDictionary() {
	multimap<string, string>data;
	queue<string>q;
	string temp = "";
	multimap<string, string>::iterator pos;
	multimap<string, string>::iterator iter;

	int x = 0;
	for (position = words.begin(); position != words.end(); ++position) {
		++x;
		if (x == 8) {
			break;
		}
		q.push(*position);
	}

	position = words.begin();
	for (; position != words.end(); ++position) {
		temp = "";
		if (*position != " ") {
			for (int x = 0; x < 3; ++x) {
				--position;
			}
			for (int x = 0; x < 3; ++x) {
				if (*position != " ") {
					temp += *position + " ";
				}
				++position;
			}
			temp += *position + " ";
			for (int x = 0; x < 3; ++x) {
				++position;
				if (*position != " ") {
					temp += *position + " ";
				}
			}
			for (int x = 0; x < 3; ++x) {
				--position;
			}
			iter = data.find(*position);
			if (iter != data.end()) {
				iter->second += "\n         " + temp;
			}
			else {
				data.insert(pair<string, string>(*position, temp));
			}
		}
		q.pop();
		q.push(*position);
	}

	for (pos = data.begin(); pos != data.end(); ++pos) {
		cout << "Key word: " << pos->first;
		cout << "\nContext: " << pos->second << "\n\n";
	}
}

