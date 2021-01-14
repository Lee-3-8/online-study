#include <iostream>
// Array를 이용한 stack 구현
/*
#define SIZE 10000
#define INF 99999999

int stack[SIZE];
int top = -1;

void push(int data) {
	if (top == SIZE - 1) {
		std::cout << "Stack overflow" << std::endl;
		return;
	}
	stack[++top] = data;
}

int pop() {
	if (top == -1) {
		std::cout << "Stack underflow" << std::endl;
		return -INF;
	}
	return stack[top--];
}

void show() {
	for (int i = top; i >= 0; i--) {
		std::cout << stack[i] << std::endl;
	}
}

int main() {
	push(7);
	push(5);
	push(4);
	pop();
	push(6);
	pop();
	show();

	return 0;
}*/

// 연결리스트를 이용한 stack 구현
#define INF 99999999

struct Node {
	int data;
	Node* next;
};

struct Stack {
	Node* top;
};

void push(Stack* stack, int data) {
	Node* node = new Node;
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

int pop(Stack* stack) {
	if (stack->top == NULL) {
		std::cout << "Stack Underflow" << std::endl;
		return -INF;
	}
	Node* node = stack->top;
	int data = node->data;
	stack->top = node->next;
	delete node;
	return data;
}

void show(Stack* stack) {
	Node* cur = stack->top;
	while (cur != NULL) {
		std::cout << cur->data << std::endl;
		cur = cur->next;
	}
}

int main() {
	Stack stack;
	stack.top = NULL;
	push(&stack, 7);
	push(&stack, 5);
	push(&stack, 4);
	pop(&stack);
	push(&stack, 6);
	pop(&stack);
	show(&stack);
	return 0;
}