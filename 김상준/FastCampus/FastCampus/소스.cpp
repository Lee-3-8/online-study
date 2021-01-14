#include <iostream>

struct Node {
	Node* prev;
	Node* next;
	int data;
};

Node* head, *tail;

void insert(int data) {
	Node* node = new Node;
	node->data = data;
	Node* cur;
	cur = head->next;
	while (cur->data < data && cur != tail) {
		cur = cur->next;
	}
	Node* prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	cur->prev = node;
	node->next = cur;
}

void removeFront() {
	Node* node = head->next;
	head->next = node->next;
	Node* next = node->next;
	next->prev = head;
	delete node;
}

void show() {
	Node* cur = head->next;
	while (cur != tail) {
		std::cout << cur->data << " ";
		cur = cur->next;
	}
}

int main() {
	head = new Node;
	tail = new Node;
	head->next = tail;
	head->prev = head;
	tail->prev = head;
	tail->next = tail;
	insert(2);
	insert(1);
	insert(3);
	insert(9);
	insert(7);
	removeFront();
	show();

	return 0;
}