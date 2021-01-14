//
//  BFS.cpp
//  FirstXCode
//
//  Created by Sangjun Kim on 2020/11/30.
//  Copyright © 2020 SJKim. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

struct Node
{
    int index;
    Node* next;
    
    Node(Node* next, int index)
    : index(index), next(next) {}
};

struct Queue
{
    Node* front;
    Node* rear;
    int count;
    
    Queue()
    : front(nullptr), rear(nullptr), count(0) {}
};

Node** a;
int n, m, c[MAX_SIZE];

void AddFront(Node* root, int index)
{
    Node* node = new Node(root->next, index);
    root->next = node;
}

void PushQueue(Queue* queue, int index)
{
    Node* node = new Node(nullptr, index);
    if (queue->count == 0)
    {
        queue->front = node;
    }
    else
    {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->count++;
}

int PopQueue(Queue* queue)
{
    if (queue->count == 0)
    {
        std::cout << "Queue Underflow.\n";
        return -INF;
    }
    Node* node = queue->front;
    int index = node->index;
    queue->front = node->next;
    delete node;
    queue->count--;
    return index;
}

// 탐색 동작 원리
// 1. 탐색 시작 노드를 큐에 삽입하고 방문 처리
// 2. 큐에서 노드를 꺼내, 해당 노드의 인접노드 중 방문하지 않은 노드들을 모두 큐에 삽입하고 방문 처리
// 3. 2번이 불가능 할 때까지 계속 수행
void BreadthFirstSearch(int start)
{
    Queue q;
    PushQueue(&q, start);
    c[start] = 1;
    while (q.count != 0)
    {
        int x = PopQueue(&q);
        std::cout << x << " ";
        Node* cur = a[x]->next;
        while (cur)
        {
            int next = cur->index;
            if (!c[next])
            {
                PushQueue(&q, next);
                c[next] = 1;
            }
            cur = cur->next;
        }
    }
}

int main()
{
    // 너비 우선 탐색 (Breadth First Search)
    // 너비를 우선으로 탐색하는 알고리즘, 맹목적으로 전체 노드를 탐색할 때 사용, 큐 자료구조에 기초
    // O(N) 시간이 소요되는 알고리즘, DFS보다 빠른 경향이 있음.
    std::cin >> n >> m;
    a = new Node*[MAX_SIZE];
    for (int i = 1; i <= n; i++)
    {
        a[i] = new Node(nullptr, 0);
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        AddFront(a[x], y);
        AddFront(a[y], x);
    }
    BreadthFirstSearch(1);
    
    return 0;
}
