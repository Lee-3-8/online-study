#include <iostream>
#define NUMBER 7

int tree[NUMBER + 1];

// 1���� N������ ���� �� ���ϱ�
int Sum(int i)
{
	int res = 0;
	while (i > 0)
	{
		res += tree[i];
		i -= (i & -i);
	}
	return res;
}

// Ư�� �ε��� �����ϱ�
void Update(int i, int dif)
{
	while (i <= NUMBER)
	{
		tree[i] += dif;
		i += (i & -i);
	}
}

// ���� �� ���ϱ�
int GetSection(int start, int end)
{
	return Sum(end) - Sum(start - 1);
}

int main()
{
	// �ε��� Ʈ��
	// �������� �� ���� ���ϴ� ��� -> �ε��� Ʈ���� Ȱ���� �ſ� �����ϰ� ����
	// O(logN)�� �ð� ���⵵
	// ���׸�Ʈ Ʈ���� ���� �޸� ȿ������ ����

	// Ư���� ���� A�� ������ ��Ʈ ���ϱ� -> A & -A�� ���� ���� �� ����

	// �� �ε����� ����, ������ ��Ʈ�� ���� �����ϰ� �ִ� ������ ������ ���
	// ex) (7 & -7) = 1 �̹Ƿ� index 7���� 7�� ���� ����Ǿ� �ִ� ��
	//     (4 & -4) = 4 �̹Ƿ� index 4���� 1 ~ 4������ ���� ����Ǿ��ִ� ��
	//     (6 & -6) = 2 �̹Ƿ� index 6���� 5 ~ 6 ������ ���� ����Ǿ��ִ� ��
	Update(1, 7);
	std::cout << Sum(7) << "\n";
	Update(2, 1);
	std::cout << Sum(7) << "\n";
	Update(3, 9);
	std::cout << Sum(7) << "\n";
	Update(4, 5);
	std::cout << Sum(7) << "\n";
	Update(5, 6);
	std::cout << Sum(7) << "\n";
	Update(6, 4);
	std::cout << Sum(7) << "\n";
	Update(7, 1);
	std::cout << Sum(7);
}