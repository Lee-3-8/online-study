#include <iostream>
#define NUMBER 7

int a[] = { 7, 1, 9, 5, 6, 4, 1 };
int tree[4 * NUMBER];

// start, end�� array a�� �ε����� �ǹ�
// node�� tree�� �ε���
int Init(int start, int end, int node)
{
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	return tree[node] = Init(start, mid, node * 2) + Init(mid + 1, end, node * 2 + 1);
}

// left, right�� ����
int Sum(int start, int end, int node, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return Sum(start, mid, node * 2, left, right) + Sum(mid + 1, end, node * 2 + 1, left, right);
}

// index�� a���� �ٲ� �ε���
// dif�� ��ȭ��
void Update(int start, int end, int node, int index, int dif)
{
	if (index < start || index > end) return;
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	Update(start, mid, node * 2, index, dif);
	Update(mid + 1, end, node * 2 + 1, index, dif);
}

int main()
{
	// ���׸�Ʈ Ʈ��
	// ���� �� - ���� ���� �����Ͱ� ���������� ������ �� Ư�� ������ ������ ���� ���ϴ� ���� �ǹ�
	// ������ ���� �� - O(N)�� �ð� ���⵵
	
	// Ʈ�� ������ ���� �� ���ϱ� - O(logN)�� �ð� ���⵵
	// ���� ���� Ʈ���� ������ ����
	// ���� �� Ʈ�� ���� - ��忡 Ư�� ���� �ε����� ���� ����
	// ���� �� Ʈ�� ���� - ���õ� ��� ��带 ����, ���� O(logN)�� �ð����⵵�� ����

	// ���� �� Ʈ�� ����
	Init(0, NUMBER - 1, 1); // ���׸�Ʈ Ʈ���� ��� ������ 1���� (root ��� index�� 1)

	// ���� �� ���ϱ�
	std::cout << Sum(0, NUMBER - 1, 1, 0, 6) << "\n";

	// ���� �� ����
	Update(0, NUMBER - 1, 1, 5, 3);

	// ���� �� �ٽ� ���ϱ�
	std::cout << Sum(0, NUMBER - 1, 1, 3, 6) << "\n";

	return 0;
}