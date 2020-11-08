#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
	char data[100];
	Node* next;
};

struct Stack {
	Node* top;
};

void push(Stack* stack, char* data) {
	Node* node = new Node;
	strcpy(node->data, data);
	node->next = stack->top;
	stack->top = node;
}

char* getTop(Stack* stack) {
	Node* top = stack->top;
	return top->data;
}

char* pop(Stack* stack) {
	if (stack->top == NULL) {
		std::cout << "Stack Underflow" << std::endl;
		return NULL;
	}
	Node* node = stack->top;
	char data[100];
	strcpy(data, node->data);
	stack->top = node->next;
	delete node;
	return data;
}

int getPriority(char* i) {
	if (!strcmp(i, "(")) return 0;
	if (!strcmp(i, "+") || !strcmp(i, "-")) return 1;
	if (!strcmp(i, "*") || !strcmp(i, "/")) return 2;
	return 3;
}

// 후위 표기법으로 전환
char* transition(Stack* stack, char** s, int size) {
	char res[1000] = "";
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
			while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])) {
				strcat(res, pop(stack)); strcat(res, " ");
			}
			push(stack, s[i]);
		}
		else if (!strcmp(s[i], "(")) push(stack, s[i]);
		else if (!strcmp(s[i], ")")) {
			while (strcmp(getTop(stack), "(")) {
				strcat(res, pop(stack)); strcat(res, " ");
			}
			pop(stack);
		}
		else {
			strcat(res, s[i]); strcat(res, " ");
		}
	}
	while (stack->top != NULL) {
		strcat(res, pop(stack)); strcat(res, " ");
	}
	return res;
}

// 후위식 계산
void calculate(Stack* stack, char** s, int size) {
	int x, y, z;
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
			x = atoi(pop(stack));
			y = atoi(pop(stack));
			if (!strcmp(s[i], "+")) z = y + x;
			if (!strcmp(s[i], "-")) z = y - x;
			if (!strcmp(s[i], "*")) z = y * x;
			if (!strcmp(s[i], "/")) z = y + x;
			char buffer[100];
			sprintf(buffer, "%d", z);
			push(stack, buffer);
		}
		else {
			push(stack, s[i]);
		}
	}
	char data[100];
	strcpy(data, getTop(stack));
	printf("%s\n", data);
}

int main() {
	Stack stack;
	stack.top = NULL;
	char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";
	int size = 1;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == ' ') size++;
	}
	char* ptr = strtok(a, " ");
	char** input = new char*[size];
	for (int i = 0; i < size; i++) {
		input[i] = new char[100];
	}
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr);
		ptr = strtok(NULL, " ");
	}
	char b[1000] = "";
	strcpy(b, transition(&stack, input, size));
	std::cout << "후위 표기법: " << b << std::endl;
	size = 1;
	for (int i = 0; i < strlen(b) - 1; i++) {
		if (b[i] == ' ') size++;
	}
	char* ptr2 = strtok(b, " ");
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr2);
		ptr2 = strtok(NULL, " ");
	}
	calculate(&stack, input, size);

	return 0;
}