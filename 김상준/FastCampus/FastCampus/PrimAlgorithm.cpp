#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits>
#define NODE_MAX 1001
#define EDGE_MAX 200001

struct Edge
{
	int cost;
	int node;
};

void Swap(Edge* a, Edge* b)
{
	Edge temp;
	temp.cost = a->cost;
	temp.node = a->node;
	a->cost = b->cost;
	a->node = b->node;
	b->cost = temp.cost;
	b->node = temp.node;
}

// -------------------- �켱���� ť -------------------- //
struct priorityQueue
{
	Edge* heap[EDGE_MAX];
	int count;
};

void Push(priorityQueue* pq, Edge* edge)
{
	if (pq->count >= EDGE_MAX) return;
	pq->heap[pq->count] = edge;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	// ����� �� ���� (�ּ��� �����)
	while (now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost)
	{
		Swap(pq->heap[now], pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

Edge* Pop(priorityQueue* pq)
{
	if (pq->count <= 0) return NULL;
	Edge* res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	// ����� �� ����
	while (leftChild < pq->count)
	{
		if (pq->heap[target]->cost > pq->heap[leftChild]->cost) target = leftChild;
		if (pq->heap[target]->cost > pq->heap[rightChild]->cost && rightChild < pq->count) target = rightChild;
		if (target == now) break;
		else
		{
			Swap(pq->heap[now], pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}

// -------------------- �׷��� -------------------- //
struct Node
{
	Edge* data;
	Node* next;
};

Node** adj;
int d[NODE_MAX];

void AddNode(Node** target, int index, Edge* edge)
{
	if (target[index] == NULL)
	{
		target[index] = new Node;
		target[index]->data = edge;
		target[index]->next = NULL;
	}
	else
	{
		Node* node = new Node;
		node->data = edge;
		node->next = target[index];
		target[index] = node;
	}
}

int main()
{
	// �ּ� ���� Ʈ�� (Minimum Spanning Tree)
	// ���� Ʈ�� - Ư�� �׷������� ��� ������ �����ϴ� �׷���
	// �ּ� ���� Ʈ���� ������ ����ġ�� ���� ���� ���� ���� Ʈ���� �ǹ� - ��� ��带 ���� �Ұǵ�, ���� ���� ����� ������ ����

	// ���� �˰��� - O(E*LogV)�� �ð� ���⵵�� ����
	// �׷������� ���� �ϳ��� ������ Ʈ�� T�� ����
	// T�� ���Ե� ���� ���Ե��� ���� ��� ������ ���� �� ����ġ�� ���� ���� ������ ã��
	// �ش� ������ ����� T�� ���Ե��� ���� ��带 Ʈ���� ���Խ�Ŵ
	// ��� ��尡 ���� �� �� ���� 2, 3 �ݺ�
	// �� ������ ���� ������ �켱���� ť�� ��� ó���ϴ� ������� ����

	int n, m;
	std::cin >> n >> m;
	adj = new Node * [n + 1];
	for (int i = 1; i <= n; i++)
	{
		adj[i] = NULL;
	}

	priorityQueue* pq = new priorityQueue;
	pq->count = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		Edge* edge1 = new Edge;
		edge1->node = b;
		edge1->cost = c;
		AddNode(adj, a, edge1);
		Edge* edge2 = new Edge;
		edge2->node = a;
		edge2->cost = c;
		AddNode(adj, b, edge2);
	}

	long long res = 0; // �� ����ġ
	Edge* start = new Edge;
	start->cost = 0; start->node = 1; Push(pq, start);
	for (int i = 1; i <= n; i++) // �� n �� ������ �ݺ���, ��� ��带 �� �� �ֵ��� �ϱ� ���� (��� �׷����� ������ ����Ǿ��־�� ��)
	{
		int nextNode = -1, nextCost = INT_MAX;
		while (true) // �鸮�� ���� ��带 ã�� ������ �켱���� ť���� ����
		{
			Edge* now = Pop(pq); // �켱���� ť(minimum heap)�� pop �� �� �ּ� cost�� ����
			if (now == NULL) break;
			nextNode = now->node;
			if (!d[nextNode])
			{
				nextCost = now->cost; break; // �鸮�� ���� ��带 ã���� break
			}
		}
		if (nextCost == INT_MAX) std::cout << "Not Connected Graph\n";
		res += nextCost;
		d[nextNode] = 1; // �ش� ��带 ��ȴٴ� ���� ����
		Node* cur = adj[nextNode];
		while (cur) // �ش� ��忡 ������ ��� �������� �켱���� ť�� ����
		{
			Push(pq, cur->data);
			cur = cur->next;
		}
	}

	std::cout << res << "\n";
}