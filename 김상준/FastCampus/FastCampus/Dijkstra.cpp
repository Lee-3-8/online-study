#include <iostream>
#include <limits.h>
#define NODE_MAX 20001
#define EDGE_MAX 600001

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

struct Node
{
	Edge* data;
	Node* next;
};

Node** adj;
int ans[NODE_MAX]; // Ư�� �������� �Ÿ��� �����ϴ� �迭 / ����ġ �迭

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
	// ���ͽ�Ʈ�� �ִ� ��� �˰��� - O(E*LogV) �ð� ���⵵�� ����
	// �� ������ ���� ������ �켱���� ť�� ��� ó���ϴ� ��� 
	// ���� ������ ���� �� ���������� ����
	// ���� ��忡�� Ư�� ������ �ִ� �Ÿ����� ���ϴ� �˰���

	// �۵� ������ ���� �˰���� ���� ���
	// Ư�� ������ ���Ե��� ���� �� ����

	// ���� ������ ���� �˰���� ��ġ��

	int n, m, k;
	std::cin >> n >> m >> k;
	adj = new Node * [n + 1];
	for (int i = 1; i <= n; i++)
	{
		adj[i] = NULL;
		ans[i] = INT_MAX; // �ʱ�ȭ �� �� ���Ѵ�� ���� (�� ���ٴ� ��)
	}

	priorityQueue* pq = new priorityQueue;
	pq->count = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		Edge* edge = new Edge;
		edge->node = b;
		edge->cost = c;
		AddNode(adj, a, edge); // ���� �׷���
	}

	ans[k] = 0;
	Edge* start = new Edge;
	start->cost = 0; start->node = k; Push(pq, start);
	while (true)
	{
		Edge* now = Pop(pq);
		if (now == NULL) break;
		int curNode = now->node;
		int curCost = now->cost;
		if (ans[curNode] < curCost) continue; // �̹� �� ����� ��ΰ� ������ ��� ����
		Node* cur = adj[curNode]; // ���� ����� ����� ���, �ش� ���� ����� �������� ��� Ȯ��
		while (cur != NULL)
		{
			Edge* temp = cur->data;
			temp->cost += curCost; // ���� ������ ���µ� �Ÿ� + �ش� ������ ���µ� �Ÿ�
			if (temp->cost < ans[temp->node]) // �� ���� ����� ��κ��� ����� ���
			{
				ans[temp->node] = temp->cost; // �ٲ��ְ�
				Push(pq, temp); // �켱���� ť�� ����
			}
			cur = cur->next;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == INT_MAX) std::cout << "INF\n";
		else std::cout << ans[i] << "\n";
	}
}