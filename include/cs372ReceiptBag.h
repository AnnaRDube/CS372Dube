#include "cs372Vector.h"
template <typename Thing>

class ReceiptBag {
private:
	Vector<int> receipt;
	Vector<Thing> bagVector;
public:
	int insert(Thing aThing) {
		static int a = 0;
		a++;
		receipt.push_back(a);
		bagVector.push_back(aThing);
		return a;
	}
	Thing pop(int removedReceipt) {
		Thing removed = remove(removedReceipt);
		return removed;
	}
	int size() {
		return (bagVector.size() - 1);
	}
	int count(Thing aThing) {
		int totalFound = 0;
		int bagvecsize = bagVector.size();
		for (int i = 0; i < bagvecsize; i++) {
			if (bagVector[i] == aThing) {
				totalFound++;
			}
		}
		return totalFound;
	}
	Thing remove(int r) {
		Thing removedItem = NULL;
		int removedReceipt = 0;
		removedItem = bagVector[r];
		removedReceipt = receipt[r];
		for (int z = r; z < size(); z++) {
			bagVector[z] = bagVector[z + 1];
			receipt[z] = receipt[z + 1];
		}
		bagVector.pop();
		receipt.pop();
		return removedItem;
	}
};
