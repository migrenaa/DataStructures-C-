#include <iostream>
using namespace std;

class Queue {
private:
	int* elements;
	int	front;
	int back;
	int capacity;

	bool isFull() {
		return back == capacity - 1;
	}

	void resize() {
		int oldCapacity = capacity;
		capacity *= 2;
		int* newElements = new int[capacity];
		int j = 0;
		for (int i = front; i < oldCapacity; i++) {
			newElements[j] = elements[i];
			j++;
		}
		front = 0;
		back = oldCapacity;
		delete[] elements;
		elements = newElements;
	}

public:

	Queue()
	{
		front = 0;
		back = -1;
		capacity = 2;
		elements = new int[capacity];
	}

	~Queue() {
		delete[] elements;
	}

	bool empty() {
		return front > back;
	}

	void enquque(int element) {
		if (isFull()) {
			resize();
		}
		elements[++back] = element;
	}

	int dequeue() {
		if (empty()) {
			cout << "The queue is empty";
			return 0;
		}
		return elements[front++];
	}

	int head() {
		if (empty()) {
			cout << "The queue is empty";
			return 0;
		}
		return elements[front];
	}
};


int main() {

	Queue queue;
	cout << queue.empty() << endl;
	cout << queue.head() << endl;
	cout << queue.dequeue() << endl;

	queue.enquque(1);

	cout << "Should be 0: " << queue.empty() << endl;
	cout << "Should be 1: " << queue.head() << endl;
	cout << "Should be 1: " << queue.dequeue() << endl;

	queue.enquque(2);
	queue.enquque(3);
	cout << "Should be 2: " << queue.dequeue() << endl;
	cout << "Should be 3: " << queue.head() << endl;

	queue.enquque(2);
	queue.enquque(2);
	queue.enquque(2);

	cout << "Should be 2: " << queue.dequeue() << endl;
	cout << "Should be 2: " << queue.dequeue() << endl;
	int a;
	cin >> a;
}