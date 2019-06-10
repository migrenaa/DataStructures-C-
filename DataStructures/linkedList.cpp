#include <iostream>
using namespace std;

struct Element {
	int data;
	Element* next;
	Element(int x)
	{
		data = x;
		next = NULL;
	}
};

class LinkedList {
private:

	Element* first;
	Element* last;

public:

	LinkedList(int data)
	{
		first = new Element(data);
		first->next = NULL;
		last = first;
	}

	~LinkedList() {
		Element* current = first;
		while (current->next != NULL) {
			delete current;
			current = current->next;
		}
	}

	bool empty() {
		return first == NULL;
	}

	void add(int element) {

		Element* newElement = new Element(element);
		newElement->next = NULL;

		if (first == NULL) {
			first = newElement;
			last = newElement;
			return;
		}
		last->next = newElement;
		last = newElement;
	}

	int remove(int position) {
		if (empty()) {
			cout << "The list is empty.";
			return 0;
		}

		if (position == 0) {
			int data = first->data;
			Element* next = first->next;
			delete first;
			first = next;
			return data;
		}

		int i = 0;
		Element* previous = first;
		Element* current = first->next;
		while (i < position - 1) {
			if (current == NULL) {
				cout << "Invalid index";
				return -1;
			}
			previous = current;
			current = current->next;
			i++;
		}

		int data = current->data;
		previous->next = current->next;
		delete current;
		return data;
	}

	int get(int position) {
		if (empty()) {
			cout << "The list is empty.";
			return -1;
		}
		int i = 0;
		Element* current = first;
		while (i < position) {
			if (current->next == NULL) {
				cout << "Invalid index";
				return -1;
			}
			current = current->next;
			i++;
		}

		return current->data;
	}
};


int main() {

	LinkedList list(1);
	cout << "Should be 0: " << list.empty() << endl;
	cout << "Should be 1: " << list.get(0) << endl;
	cout << list.get(1) << endl;
	cout << "Should be 1: " << list.remove(0) << endl;

	list.add(0);
	list.add(1);
	list.add(2);
	cout << "Should be 1: " << list.remove(1) << endl;
	cout << "Should be 2: " << list.get(1) << endl;

	cout << "Should be 0: " << list.remove(0) << endl;
	cout << "Should be 2: " << list.remove(0) << endl;

	cout << "Should be 1: " << list.empty() << endl;

	int a;
	cin >> a;
}