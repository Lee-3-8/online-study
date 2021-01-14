#include <iostream>
#include <limits.h>
#define SIZE 1000

int a[SIZE];

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	// selection sort
	int n, min, index;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		min = INT_MAX;
		for (int j = i; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				index = j;
			}
		}
		swap(&a[i], &a[index]);
	}
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	
	//insertion sort
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int j = i + 1;
		while (j >= 1 && a[j - 1] > a[j]) {
			swap(&a[j], &a[j - 1]);
			j--;
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
}