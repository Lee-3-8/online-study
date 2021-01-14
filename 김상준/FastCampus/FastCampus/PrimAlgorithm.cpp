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

// -------------------- 우선순위 큐 -------------------- //
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
	// 상향식 힙 구성 (최소힙 만들기)
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
	// 하향식 힙 구성
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

// -------------------- 그래프 -------------------- //
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
	// 최소 신장 트리 (Minimum Spanning Tree)
	// 신장 트리 - 특정 그래프에서 모든 정점을 포함하는 그래프
	// 최소 신장 트리는 간선의 가중치의 합이 가장 작은 신장 트리를 의미 - 모든 노드를 연결 할건데, 가장 적은 비용의 간선만 선택

	// 프림 알고리즘 - O(E*LogV)의 시간 복잡도를 가짐
	// 그래프에서 정점 하나를 선택해 트리 T에 포함
	// T에 포함된 노드와 포함되지 않은 노드 사이의 간선 중 가중치가 가장 작은 간선을 찾음
	// 해당 간선에 연결된 T에 포함되지 않은 노드를 트리에 포함시킴
	// 모든 노드가 포함 될 때 까지 2, 3 반복
	// 각 간선에 대한 정보를 우선순위 큐에 담아 처리하는 방식으로 구현

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

	long long res = 0; // 총 가중치
	Edge* start = new Edge;
	start->cost = 0; start->node = 1; Push(pq, start);
	for (int i = 1; i <= n; i++) // 총 n 번 과정을 반복해, 모든 노드를 갈 수 있도록 하기 위함 (대신 그래프가 완전히 연결되어있어야 함)
	{
		int nextNode = -1, nextCost = INT_MAX;
		while (true) // 들리지 않은 노드를 찾을 때까지 우선순위 큐에서 추출
		{
			Edge* now = Pop(pq); // 우선순위 큐(minimum heap)라서 pop 할 시 최소 cost가 보장
			if (now == NULL) break;
			nextNode = now->node;
			if (!d[nextNode])
			{
				nextCost = now->cost; break; // 들리지 않은 노드를 찾으면 break
			}
		}
		if (nextCost == INT_MAX) std::cout << "Not Connected Graph\n";
		res += nextCost;
		d[nextNode] = 1; // 해당 노드를 들렸다는 것을 저장
		Node* cur = adj[nextNode];
		while (cur) // 해당 노드에 인접한 모든 간선들을 우선순위 큐에 삽입
		{
			Push(pq, cur->data);
			cur = cur->next;
		}
	}

	std::cout << res << "\n";
}