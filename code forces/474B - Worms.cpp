#include <iostream>

int search(int* pile, int label, int start, int end)
{
	int mid = (start + end) / 2;
	if (pile[mid - 1] < label && pile[mid] >= label) return mid;
	else if (pile[mid - 1] >= label) return search(pile, label, start, mid - 1);
	else return search(pile, label, mid + 1, end);
}

int main()
{
	int n;
	std::cin >> n;

	int totalWorms = 0;
	int* pile = new int[n + 1];
	pile[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		std::cin >> num;
		totalWorms += num;
		pile[i + 1] = totalWorms;
	}

	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		int label;
		std::cin >> label;
		std::cout << search(pile, label, 1, n) << "\n";
	}

	delete[] pile;
	return 0;
}