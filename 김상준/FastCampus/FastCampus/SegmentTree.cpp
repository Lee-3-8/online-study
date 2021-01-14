#include <iostream>
#define NUMBER 7

int a[] = { 7, 1, 9, 5, 6, 4, 1 };
int tree[4 * NUMBER];

// start, end는 array a의 인데스를 의미
// node는 tree의 인덱스
int Init(int start, int end, int node)
{
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	return tree[node] = Init(start, mid, node * 2) + Init(mid + 1, end, node * 2 + 1);
}

// left, right는 구간
int Sum(int start, int end, int node, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return Sum(start, mid, node * 2, left, right) + Sum(mid + 1, end, node * 2 + 1, left, right);
}

// index는 a에서 바꿀 인덱스
// dif는 변화량
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
	// 세그먼트 트리
	// 구간 합 - 여러 개이 데이터가 연속적으로 존재할 때 특정 범위의 데이터 합을 구하는 것을 의미
	// 선형적 구간 합 - O(N)의 시간 복잡도
	
	// 트리 구조로 구간 합 구하기 - O(logN)의 시간 복잡도
	// 완전 이진 트리에 데이터 삽입
	// 구간 합 트리 생성 - 노드에 특정 범위 인덱스의 값을 저장
	// 구간 합 트리 수정 - 관련된 모든 노드를 수정, 역시 O(logN)의 시간복잡도로 수행

	// 구간 합 트리 생성
	Init(0, NUMBER - 1, 1); // 세그먼트 트리는 노드 시작을 1부터 (root 노드 index가 1)

	// 구간 합 구하기
	std::cout << Sum(0, NUMBER - 1, 1, 0, 6) << "\n";

	// 구간 합 갱신
	Update(0, NUMBER - 1, 1, 5, 3);

	// 구간 합 다시 구하기
	std::cout << Sum(0, NUMBER - 1, 1, 3, 6) << "\n";

	return 0;
}