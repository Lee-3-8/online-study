#include <iostream>
#define NUMBER 7

int tree[NUMBER + 1];

// 1부터 N까지의 구간 합 구하기
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

// 특정 인덱스 수정하기
void Update(int i, int dif)
{
	while (i <= NUMBER)
	{
		tree[i] += dif;
		i += (i & -i);
	}
}

// 구간 합 구하기
int GetSection(int start, int end)
{
	return Sum(end) - Sum(start - 1);
}

int main()
{
	// 인덱스 트리
	// 구간합을 더 쉽게 구하는 방법 -> 인덱스 트리를 활용해 매우 간단하게 구현
	// O(logN)의 시간 복잡도
	// 세그먼트 트리에 비해 메모리 효율성도 높음

	// 특정한 숫자 A의 마지막 비트 구하기 -> A & -A를 통해 구할 수 있음

	// 각 인덱스에 대해, 마지막 비트를 내가 저장하고 있는 값들의 개수로 계산
	// ex) (7 & -7) = 1 이므로 index 7에는 7의 값만 저장되어 있는 것
	//     (4 & -4) = 4 이므로 index 4에는 1 ~ 4까지의 합이 저장되어있는 것
	//     (6 & -6) = 2 이므로 index 6에는 5 ~ 6 까지의 합이 저장되어있는 것
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