#include "cs372List.h"
using namespace std;
template <typename Thing>
class Bag {
private:
	int sizeOfList = 0;
	List<Thing> bagList;
public:
	void insert(Thing aThing) {
		bagList.push_back(aThing);
		++sizeOfList;
	}
	Thing pop() {
		Thing item = bagList.back();
		bagList.pop_back();
		--sizeOfList;
		return item;
	}
	int size() {
		return sizeOfList;
	}
	int count(Thing aThing) {
		int totalFound = 0;
		Thing item;
		for (int i = 0; i < sizeOfList; i++) {
			item = bagList.back();
			if (item == aThing){
				totalFound++;
			}
			bagList.push_front(item);
			bagList.pop_back();
		}
		return totalFound;
	}
};