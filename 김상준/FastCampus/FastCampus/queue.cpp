#include <iostream>

#define SIZE 10000
#define INF 99999999

//int queue[SIZE];
//int front = 0;
//int rear = 0;
//
//void push(int data) {
//	if (rear >= SIZE) {
//		std::cout << "Queue Overflow" << std::endl;
//		return;
//	}
//	queue[rear++] = data;
//}
//
//int pop() {
//	if (front == rear) {
//		std::cout << "Queue Underflow" << std::endl;
//		return -INF;
//	}
//	return queue[front++];
//}
//
//void show() {
//	for (int i = front; i < rear; i++) {
//		std::cout << queue[i] << std::endl;
//	}
//}
//
//int main() {
//	push(7);
//	push(5);
//	push(4);
//	pop();
//	push(6);
//	pop();
//	show();
//	return 0;
//}

struct Node {
	int data;
	Node* next;
};

struct Queue {
	Node* front;
	Node* rear;
	int count;

	Queue() : front(NULL), rear(NULL), count(0) {}
};

void push(Queue* queue, int data) {
	Node* node = new Node;
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) {
		queue->front = node;
	}
	else {
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;
}

int pop(Queue* queue) {
	if (queue->count == 0) {
		std::cout << "Queue Underflow\n";
		return -INF;
	}
	Node* node = queue->front;
	int data = node->data;
	queue->front = node->next;
	delete node;
	queue->count--;
	return data;
}

void show(Queue* queue) {
	Node* cur = queue->front;
	while (cur != NULL) {
		std::cout << cur->data << std::endl;
		cur = cur->next;
	}
}

int main() {
	Queue queue;
	push(&queue, 7);
	push(&queue, 5);
	push(&queue, 4);
	pop(&queue);
	push(&queue, 6);
	pop(&queue);
	show(&queue);
	return 0;
}