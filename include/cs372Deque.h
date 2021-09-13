#ifndef cs372Deque_H
#define cs372Deque_H
template <typename T>
class Deque : public Container {
private:
	class Node {
	public:
		T data;
		Node* tail;
		Node* next;
		Node* prev;
	};
	Node* head = nullptr;
	Node* tail = nullptr;
	size_t length = 0;
	size_t max = 100;

public:
	Deque() : head(nullptr), tail(nullptr) {}
	Deque(Deque& rhs) {
		clear();
		head = rhs.head;
		tail = rhs.tail;
	}
	Deque(T nData) {
		setupDeque();
		head->data = nData;
	}
	void push_front(T data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = head;
		newNode->prev = nullptr;
		if (empty()) {
			head = newNode;
			tail = newNode;
		}
		else {
			head->prev = newNode;
			head = newNode;
		}
		length++;
	}
	T pop_front() {
		Node* firstNode = head;
		T save = firstNode->data;
		if (firstNode != nullptr) {
			head = head->next;
			tail->prev = nullptr;
			delete firstNode;
		}
		length--;
		return save;
	}
	void push_back(T data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = nullptr;
		newNode->prev = tail;
		if (empty()) {
			tail = newNode;
			head = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}
	T pop_back() {
		Node* lastNode = tail;
		T save = lastNode->data;
		if (lastNode != nullptr) {
			tail = tail->prev;
			tail->next = nullptr;
			delete lastNode;
		}
		length--;
		return save;
	}
	void traverse() {
		Node* current = head;
		while (current != nullptr) {
			doIt(current->data);
			current = current->next;
		}
	}
	size_t size() override {
		return length;
	}
	size_t max_size() override {
		return max;
	}
	bool empty() override {
		return (head == nullptr);
	}
	void swap(Container& x, Container& y) override {
		Container* tempX = &x;
		while (tempX != nullptr) {
			tempX = &x;
			x = y;
			y = *tempX;
		}
	}
	void clear() override {
		Node* temp = nullptr;
		Node* current = tail;
		while (current != nullptr) {
			temp = current->prev;
			delete current;
			current = temp;
		}
		length = 0;
	}
};
#endif