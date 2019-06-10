#include <iostream>
using namespace std;

class Stack {
private:
	int* elements;
	int topIndex;
	int capacity;

	bool isFull() {
		return topIndex == capacity - 1;
	}

	void resize() {
		int oldCapacity = capacity;
		capacity *= 2;
		int* newElements = new int[capacity];
		for (int i = 0; i < oldCapacity; i++) {
			newElements[i] = elements[i];
		}
		delete[] elements;
		elements = newElements;
	}

public:

	Stack()
	{
		topIndex = -1;
		capacity = 10;
		elements = new int[capacity];
	}

	~Stack() {
		delete[] elements;
	}

	bool empty() {
		return topIndex == -1;
	}

	void push(int element) {
		if (isFull()) {
			resize();
		}
		elements[++topIndex] = element;
		return;
	}

	int pop() {
		if (empty()) {
			cout << "The stack is empty";
			return 0;
		}
		return elements[topIndex--];
	}

	int top() {
		if (empty()) {
			cout << "The stack is empty";
			return 0;
		}
		return elements[topIndex];
	}
};
//
//
//int main() {
//
//	Stack stack;
//	cout << stack.empty() << endl;
//	cout << stack.top() << endl;
//	cout << stack.pop() << endl;
//
//	stack.push(1);
//
//	cout << "Should be 0: " << stack.empty() << endl;
//	cout << "Should be 1: " << stack.top() << endl;
//	cout << "Should be 1: " << stack.pop() << endl;
//
//	stack.push(2);
//	stack.push(3);
//	cout << "Should be 3: " << stack.pop() << endl;
//	cout << "Should be 2: " << stack.top() << endl;
//	
//	
//	int a;
//	cin >> a;
//}