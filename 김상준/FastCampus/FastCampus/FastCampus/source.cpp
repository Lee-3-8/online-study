#include <iostream>

struct Node {
	int data;
	Node* next;

	Node();
};

Node* head;

int main() {
	head = new Node;
	head->data = 1;
}