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
int ans[NODE_MAX]; // 특정 노드까지의 거리를 저장하는 배열 / 가중치 배열

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
	// 다익스트라 최단 경로 알고리즘 - O(E*LogV) 시간 복잡도를 가짐
	// 각 간선에 대한 정보를 우선순위 큐에 담아 처리하는 방식 
	// 음의 간선이 없을 때 정상적으로 동작
	// 시작 노드에서 특정 노드까지 최단 거리값을 구하는 알고리즘

	// 작동 원리는 프림 알고리즘과 거의 흡사
	// 특정 노드들이 포함되지 않을 수 있음

	// 위의 구조는 프림 알고리즘과 일치함

	int n, m, k;
	std::cin >> n >> m >> k;
	adj = new Node * [n + 1];
	for (int i = 1; i <= n; i++)
	{
		adj[i] = NULL;
		ans[i] = INT_MAX; // 초기화 할 때 무한대로 설정 (못 간다는 뜻)
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
		AddNode(adj, a, edge); // 방향 그래프
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
		if (ans[curNode] < curCost) continue; // 이미 더 가까운 경로가 존재할 경우 무시
		Node* cur = adj[curNode]; // 가장 가까운 경로일 경우, 해당 노드와 연결된 간선들을 모두 확인
		while (cur != NULL)
		{
			Edge* temp = cur->data;
			temp->cost += curCost; // 다음 노드까지 가는데 거리 + 해당 노드까지 오는데 거리
			if (temp->cost < ans[temp->node]) // 위 값이 저장된 경로보다 가까울 경우
			{
				ans[temp->node] = temp->cost; // 바꿔주고
				Push(pq, temp); // 우선순위 큐에 삽입
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