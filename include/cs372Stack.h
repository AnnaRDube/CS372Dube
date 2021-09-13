#ifndef PASSFAILACTIVITY_H
#define cs372Stack_H
#include "cs372Deque.h"
template <typename T>
class Stack : Container {
private:
	Deque<T>* stackDeque = new Deque<T>();
public:
	Stack() {}
	Stack(T data) {push(data)}
	Stack(Stack& rhs) {}
	~Stack() { delete stackDeque; }
	void push(T data) { stackDeque->push_front(data); }
	T pop() { return stackDeque->pop_front(); }
	void traverse(void (*doIt) (T data)) {
		stackDeque->traverse(doIt);
	};
	size_t size() override {
		return stackDeque->size();
	}
	size_t max_size() override {
		return stackDeque->max_size();
	}
	bool empty() override { return stackDeque->empty(); }
	void swap(Container& x, Container& y) override {
		stackDeque->swap(x, y);
	}
	void clear() override {
		stackDeque->clear();
	}
};
#endif